#include "client.ih"

#include <iostream>

void Client::operator()(Storage &warehouse, string filename)
{
    ofstream output(filename);

    while(true)
    {
        if (!warehouse.empty())
        {   
            string out = warehouse.front();

            //only process if no other client did
            if  (warehouse.pop(out)) 
            {
                output << out <<'\n';
                output.flush();
                ++d_size;
            }
        }
        else if(warehouse.finished())
            break;
        else
            this_thread::sleep_for(chrono::seconds(1));

        cout.flush();
    }   
}