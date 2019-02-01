#include "client.ih"

void Client::operator()(Storage &warehouse, string filename)
{
    ofstream output(filename);

    while (!warehouse.empty() || !warehouse.finished())
    {
        if (!warehouse.empty())
        {   
            string out = warehouse.front();
            if  (warehouse.pop(out)) 
            {
                output << out <<'\n';
                ++d_size;
            }
        }
        else
            this_thread::sleep_for(chrono::seconds(1));
    }   
}