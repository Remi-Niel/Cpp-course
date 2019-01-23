#include "main.ih"

int main(int argc, char **argv)
{
    Storage warehouse{};

    vector<Client> clients;
    vector<thread> threads;

    for (size_t idx = 1; idx < argc; ++idx)
    {
        clients.push_back(Client());    //Keep track of client object
    }

    for (size_t idx = 1; idx < argc; ++idx)
    {
        threads.push_back(std::thread(ref(clients[idx-1]),ref(warehouse), argv[idx])); 
    }
    
    string in;

    while (cin >> in)
    {
        if (in != "\\")         //If more lines follow
            warehouse.push(in);
        else                    //Else stop and inform workers are done
        {
            cout <<"finished\n";
            warehouse.setFinished(); 
            break;
        }
    }    

    for(thread &thr: threads)
        thr.join();

    for(Client &cl: clients)
        cout << cl.size() << '\n';

    
}