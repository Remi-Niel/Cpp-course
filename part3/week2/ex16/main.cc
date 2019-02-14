#include "main.ih"

int main(int argc, char **argv)
{

    Storage<string> storage;

    vector<string *> &internal = storage.data();

    internal.push_back(new string{"hoi"});
    internal.push_back(new string{"dit"});
    internal.push_back(new string{"is"});
    internal.push_back(new string{"ongesorteerde"});
    internal.push_back(new string{"text"});
    internal.push_back(new string{"volgens"});
    internal.push_back(new string{"mij"});
    internal.push_back(new string{"maar"});
    internal.push_back(new string{"wat"});
    internal.push_back(new string{"weet"});
    internal.push_back(new string{"ik"});
    internal.push_back(new string{"er"});
    internal.push_back(new string{"nou"});
    internal.push_back(new string{"van"});

    cout << "unsorted:\n";
    for (auto str : storage)
    {
        cout << str << "\n";
    }    

}
