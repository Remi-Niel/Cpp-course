#include "main.ih"

int main(int argc, char **argv)
{
    Storage warehouse;
    string file = "test";
    thread thr(worker, ref(warehouse), ref(file));

    string in;
    
    while (cin >> in && in != "\\") //Repeat until a single \ is encountered
        warehouse.push(in);
        
    warehouse.setFinished(); 

    thr.join();
    
}