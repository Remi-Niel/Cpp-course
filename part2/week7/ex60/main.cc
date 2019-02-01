#include "main.ih"

int main(int argc, char **argv)
{
    Storage warehouse{};

    vector<Client> clients;

    for (size_t idx = 1; idx < argc; ++idx)
        clients.push_back(Client());    //Keep track of client object


    vector<thread> threads;
    threads.resize(clients.size());

    //Construct a thread for every client and store it in threads
    transform(clients.begin(), clients.end(), argv + 1, threads.begin(), 
        [&](Client &client, char * file)
        {
            return thread(ref(client), ref(warehouse), file);
        }
    );
    
    string in;
    while (cin >> in && in != "\\") //Repeat until a single \ is encountered
        warehouse.push(in);

    warehouse.setFinished();

    for (thread &thr: threads)
        thr.join();

    for (Client &cl: clients)
        cout << cl.size() << '\n';

    
}