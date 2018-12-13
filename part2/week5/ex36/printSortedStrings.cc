#include <queue>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	priority_queue<string> string_queue;
	string input;

	while (cin >> input)
		string_queue.push(input);

	while (string_queue.size())
	{
		cout << string_queue.top() << '\n';
		string_queue.pop();
	}
}