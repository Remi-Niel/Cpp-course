#include "main.ih"

int main(int argc, char **argv)
{
    Storage warehouse{};

    thread thr(worker,&warehouse, "test");

    string in;

    while (cin >> in)
    {
        if (in != "\\")
            warehouse.push(in);
        else
        {
            warehouse.setFinished(); 
            break;
        }
    }    

    thr.join();
    
}