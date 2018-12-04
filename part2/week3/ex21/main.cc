#include <iostream>
#include <string>

using namespace std;

class KiloByte
{
    public:
        KiloByte();

    protected:
        char *d_bytes;
};

class NullTerminatedKiloByte : public KiloByte
{
    public:
        NullTerminatedKiloByte(string const &str);
};

KiloByte::KiloByte()
{
    d_bytes = new char[1000];
}

//for the sake of brevity str.size() < = 1000;
NullTerminatedKiloByte::NullTerminatedKiloByte(string const &str)
{
    for (size_t idx = 0; idx != str.size(); ++idx)
        d_bytes[idx] = str[idx];
}