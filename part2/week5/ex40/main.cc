#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "vectorwrapper/vectorwrapper.h"

using namespace std;

int main()
{
	vector<string> strings;
    VectorWrapper wrapper;
	string input;

	// grab all strings fropm input and add them to the vector if it is not
    // already in the vector
	while (cin >> input)
    {
        cout << input << "\n";
        if (find(strings.begin(), strings.end(), input) == strings.end())
        {    
            strings.push_back(input);
            wrapper += input;
        }
    }

    cout << "Size: " << strings.size() << " , capacity: " << strings.capacity() << '\n';

    strings.push_back(string("extra"));
    
    cout << "Size: " << strings.size() << " , capacity: " << strings.capacity() << '\n';
    
    vector<string>(strings).swap(strings); // Sheds excess capacity
    
    cout << "Size: " << strings.size() << " , capacity: " << strings.capacity() << "\n\n";


    cout << "Size: " << wrapper.size() << " , capacity: " << wrapper.capacity() << '\n';

    wrapper += string("extra");

    cout << "Size: " << wrapper.size() << " , capacity: " << wrapper.capacity() << '\n';

    VectorWrapper(wrapper).swap(wrapper); // Sheds excess capacity

    cout << "Size: " << wrapper.size() << " , capacity: " << wrapper.capacity() << '\n';
}