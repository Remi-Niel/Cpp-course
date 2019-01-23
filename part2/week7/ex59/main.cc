#include "main.ih"

int main(int argc, char **argv)
{
    Storage warehouse{};

    thread thr(worker,&warehouse, "test");

    string in;

    while (cin >> in)
    {
        if (in != "\\")         //If more lines follow
            warehouse.push(in);
        else                    //Else stop and inform workers done
        {
            warehouse.setFinished(); 
            break;
        }
    }    

    thr.join();
    
}