#include "main.ih"

int main(int argc, char **argv, char **env)
{
	Strings set2(env);

	char const *test; 
	string test1;

	set2.at(test, 2);
	set2.at(test1, 2);

	cout << test << ' ' << test1 << ' ' << set2.size() << ' ' << set2.data() << '\n';

	stringsData dat = set2.release();
	cout << set2.size() << ' ' << set2.data() << '\n';

	cout << dat.strings[2] << '\n';
}
