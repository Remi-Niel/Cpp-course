#include "producer.ih"

void Producer::worker()
{
    while (true)
    {
        string source = next();

        if (source == "")
            return;

        Result result = compile(source);

        if (!result.d_success)
        {
            if (!set_invalid()) //another thread had errors already.
                return;
            
            cout << "failed to compile file.\n";
            fs::remove(result.d_outfile);
        }
    }
}