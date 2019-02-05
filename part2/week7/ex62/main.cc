#include "main.ih"

int main(int argc, char* argv[])
{
    TaskThreads tt{argc, argv};
    tt.run();
    tt.showTime();
}