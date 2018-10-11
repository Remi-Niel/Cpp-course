#include "main.ih"

int main()
{
    CharCount cc;
    size_t total = cc.count(cin);

    cout << "total: " << total << "\n";

    CharInfo const &info = cc.info();
    for (size_t idx = 0; idx < info.nChar; ++idx)
        showChar(info.ptr[idx]);
}