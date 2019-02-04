#include "main.ih"

void worker(Storage &warehouse, string const &filename)
{
    ofstream output(filename);

    while (!warehouse.empty() || !warehouse.finished())
    {
        if (!warehouse.empty())
        {   
            string out = warehouse.front();
            if  (warehouse.pop(out)) 
                output << out <<'\n';
        }
        else
            this_thread::sleep_for(chrono::seconds(1));
    }    
}