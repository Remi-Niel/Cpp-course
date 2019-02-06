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
            
            report_errors(result.d_outfile);
            fs::remove(result.d_outfile);
        }
    }
}