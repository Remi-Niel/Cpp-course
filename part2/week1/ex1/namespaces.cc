#include <iostream>

namespace First
{
	enum Enum 
	{};

	void fun(Enum symbol)
	{
		std::cout << "First::fun() called\n";
	}
}

namespace Second
{
	void fun(First::Enum symbol)
	{
		std::cout << "Second::fun() called\n";
	}
}

int main()
{
	First::Enum x;
	fun(x);
}