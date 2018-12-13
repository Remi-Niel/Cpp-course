#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	priority_queue<string> string_queue;
	string input;

	// grab all strings fropm input and push them onto the priority queue
	while (cin >> input)
		string_queue.push(input);

	// print the top string, pop it off, repeat
	while (string_queue.size())
	{
		cout << string_queue.top() << '\n';
		string_queue.pop();
	}
}