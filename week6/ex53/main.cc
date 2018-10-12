#include "main.ih"

int main(int argc, char **argv, char **env)
{
	Strings set(env);

	string **data = set.data();

	for (size_t idx = 0; idx != set.size(); ++idx)
		cout << *data[idx] <<'\n';
}