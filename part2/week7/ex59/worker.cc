#include "main.ih"

void worker(Storage *warehouse, string filename)
{
    ofstream output(filename);
    
    while(true)
    {
        if (!warehouse->empty())
        {   
            string out = warehouse->front();
            output << out <<'\n';
            output.flush();
            warehouse->pop();
        }
        else
            this_thread::sleep_for(chrono::seconds(1));
    }   
}