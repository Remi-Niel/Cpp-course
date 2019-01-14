#include "main.ih"

vector<string> read_input()
{
    string input;
    set<string> buffer;

    while(cin >> input)
        buffer.insert(input);

    return vector<string>(buffer.begin(), buffer.end());
}

int main()
{
	vector<string> strings = read_input();
    cout << "Size: " << strings.size() << " , capacity: "
        << strings.capacity() << '\n';

    strings.push_back(string("extra"));
    cout << "Size: " << strings.size() << " , capacity: "
        << strings.capacity() << '\n';
    
    vector<string>(strings).swap(strings); // Sheds excess capacity
    cout << "Size: " << strings.size() << " , capacity: " 
        << strings.capacity() << "\n\n";


    VectorWrapper wrapper;
    cout << "Size: " << wrapper.size() << " , capacity: " 
        << wrapper.capacity() << '\n';

    wrapper += string("extra");
    cout << "Size: " << wrapper.size() << " , capacity: " 
        << wrapper.capacity() << '\n';

    VectorWrapper(wrapper).swap(wrapper); // Sheds excess capacity
    cout << "Size: " << wrapper.size() << " , capacity: "
        << wrapper.capacity() << '\n';
}
