#include "main.ih"

map<ostream*, recursive_mutex> TSosWrap::s_mutex{};

void f1()
{
    TSosWrap{ std::cout } << "one " << "two " << "three ";
}
    
void f2()
{
    TSosWrap tout{ std::cout };
    tout << "four "  << "five " << "six ";
    f1();
    tout << '\n';
}

int main()
{
    vector<thread> threads;
    for (size_t ix = 0; ix != 100; ++ix)
        threads.push_back(thread(f2));

    for (auto &thread: threads)
        thread.join();
}