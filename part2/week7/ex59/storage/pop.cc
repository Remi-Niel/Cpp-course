#include "storage.ih"

// Signature has been changed such that the worker
// removes the string it expects to remove from the queue.
// This is checked because in between the call front() and 
// pop() it could happen that another worker removes the string. 

//It also works in cases where strings are repeated multiple times.
//For example take the following queue with three workers:
// {"a", "a", "b"}
// The three workers start en call front(), all get "a" as string.
// Now they call pop("a"). However only worker 1 gets access and
// removes "a" from the queue and gets true returned, hence it adds
// it to its file. 
// {"a","b"} //current queue
// Same happens for worker 2
// {"b"} //current queue
// Worker 3 gets false returned because "a" != "b" hence it doesn't add
// "a" to its file.
// {"b"} //current queue
// Most likely worker 1 and 2 also try the "a" again. After which worker 3
// succeeds with "b".

bool Storage::pop(string &str)
{
    lock_guard<mutex> lg(qMutex);
    if (d_data.size() > 0 || d_data.front() == str)
    {    
        d_data.pop();
        return true;
    }

    return false;
}
