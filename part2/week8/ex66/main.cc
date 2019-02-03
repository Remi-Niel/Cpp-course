#include <thread>
#include <future>
#include <iostream>

using namespace std;

string threadFun(){
    cerr << "entry\n";
    
    this_thread::sleep_for(chrono::seconds(5));
    cerr << "first cerr\n";

    this_thread::sleep_for(chrono::seconds(5));
    cerr << "second cerr\n";

    return "end the program";
}

int main(int argc, char ** argv)
{
    size_t count = 0;

    auto fut = async(launch::async, threadFun);

    // We didn't combine the wait_for and sleep_for because otherwise
    // the output would not be the same as stated in the exercise.
    while (fut.wait_for(chrono::seconds(0)) != future_status::ready)
    {
        this_thread::sleep_for(chrono::seconds(1));    
        cerr << "inspecting: " << ++count << '\n';
    }   
    cerr << "done\n";
}
