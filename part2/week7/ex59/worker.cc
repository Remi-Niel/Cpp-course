#include "main.ih"

void worker(Storage *warehouse, string filename)
{
    ofstream output(filename);
    
    while(true)
    {
        if (!warehouse->empty())
        {   
            string out = warehouse->front();
            if(warehouse->pop(out))
            {
                output << out <<'\n';
                output.flush();
            }
        }
        else if(warehouse->finished())
            break;
        else
            this_thread::sleep_for(chrono::seconds(1));
    }   
}