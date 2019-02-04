#include "main.ih"

int main(int argc, char **argv)
{
    Storage warehouse;
    thread thr(worker, ref(warehouse), "test");

    string in;
    
    while (cin >> in && in != "\\") //Repeat until a single \ is encountered
        warehouse.push(in);
        
    warehouse.setFinished(); 

    thr.join();
    
}