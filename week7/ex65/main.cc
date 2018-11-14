#include "main.ih"

int main(int argc, char *argv[])
{
	bool a_flag = false;
	size_t idx = 1;
	size_t argnum = static_cast<size_t>(argc);

	if (argnum == 2)
	{
		if (argv[1] == "-a"s)
		{
			a_flag = true;
			++idx;
		}
	}
	else if (argnum > 2)
	{
		if (argv[1] != "-a"s)
		{
			cout << "Usage:\n";
			cout << "    ./ec [-a] [filename(s)]\n";
			return -1;
		}

		a_flag = true;
		++idx;
	}

	if (argnum == idx)
		parse_file("/usr/include/linux/acct.h", a_flag);
	else
	{
		for (; idx < argnum; ++idx)
			parse_file(argv[idx], a_flag);
	}


	

}