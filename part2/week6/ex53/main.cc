#include <algorithm>
#include <filesystem>
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>

using namespace std;
namespace fs = std::filesystem;

void copyFile(const string &src, const string &dest)
{
    fs::copy_file(src, dest);
}

void copyFile2(istream &in, ostream &out)
{
    out << in.rdbuf();
}

void copyFile3(istream &in, ostream &out)
{
    std::copy
    (
        istreambuf_iterator<char>(in),
        istreambuf_iterator<char>(),
        ostreambuf_iterator<char>(out)
    );
}

void copyFile4(istream &in, ostream &out)
{
    vector<char> buffer;

    in.seekg(0, ios::end);
    size_t filesize = in.tellg();
    
    buffer.resize(filesize);
    in.seekg(0);
    in.read(buffer.data(), filesize);
    out.write(buffer.data(), filesize);
}

void copyFile5(istream &in, ostream &out)
{
    for_each
    (
        istreambuf_iterator<char>(in),
        istreambuf_iterator<char>(),
        [&](char c)
        {
            out << c;
        }
    );
}

int main()
{
    //
}