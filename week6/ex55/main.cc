#include "main.ih"

int main(int argc, char **argv, char **env)
{
	Strings set(env);
	Strings set1(argc, argv);
	Strings set2(cin);

	string *data = set.data();
	string *data1 = set1.data();
	string *data2 = set2.data();

	for (string *tmp = data; tmp != data + set.size(); ++tmp)
		cout << *tmp <<'\n';
	cout << '\n';
	for (string *tmp = data1; tmp != data1 + set1.size(); ++tmp)
		cout << *tmp <<'\n';
	cout << '\n';
	for (string *tmp = data2; tmp != data2 + set2.size(); ++tmp)
		cout << *tmp <<'\n';
}