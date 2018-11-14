#include <iostream>

class Demo
{
    size_t *d_numbers = 0;
    size_t d_entries = 0;
    size_t d_memsize = 10;

    public:
        Demo()
        {
            std::cout << "no-argument constructor called!\n";
            d_numbers = new size_t[d_memsize];
        }

        Demo(size_t entry)
        {
            std::cout << "1-argument constructor called!\n";
            d_numbers = new size_t[d_memsize];
            d_numbers[d_entries++] = entry;
        }

        Demo(Demo const &other)
        :
            d_entries(other.d_entries),
            d_memsize(other.d_memsize)
        {
            std::cout << "copy constructor called!\n";
            d_numbers = new size_t[d_memsize];
            for (size_t index = 0; index != d_entries; ++index)
            {
                d_numbers[index] = other.d_numbers[index];
            }
        }

        Demo(Demo &&tmp)
        :
            d_numbers(tmp.d_numbers),
            d_entries(tmp.d_entries),
            d_memsize(tmp.d_memsize)
        {
            std::cout << "move constructor called!\n";
            tmp.d_numbers = 0;
        }

        Demo &operator=(Demo &&tmp)
        {
            std::cout << "overloaded move assignment operator called!\n";
            swap(tmp);
            return *this;
        }

        Demo &operator=(Demo const &other)
        {
            std::cout << "overloaded copy assignment operator called!\n";
            Demo tmp{ other };
            return *this = std::move(tmp);
        }

        ~Demo()
        {
            std::cout << "destructor called!\n";
            delete[] d_numbers;
        }

        void swap(Demo &other)
        {
            std::cout << "swapping!\n";
            std::swap(d_numbers, other.d_numbers);
            std::swap(d_entries, other.d_entries);
            std::swap(d_memsize, other.d_memsize);
        }

        size_t const firstNum()     // function only to use in demonstration
        {
            return d_numbers[0];
        }
};

Demo factory()
{
	Demo ret;
	return ret;
}

Demo factory(size_t number)
{
    Demo ret(number);
    return ret;
}

void firstIs42(Demo object)         // function only to use in demonstration
{
    if (object.firstNum() == 42)
        std::cout << "first number is 42\n";
    else
        std::cout << "first number is not 42\n";
}

int main()
{
        // copy elision may be used in the following line to create the object
        // directly in firstIs42's 'object' stack space rather than in
        // the 'ret' space of the factory function
	firstIs42(factory(42));

        // the move constructor is called as an rvalue is passed in
    Demo moveConDemo(std::move(factory(50)));

        // the move assignment operator is used to move the anonymous demo
        // object to moveDemo
    Demo moveDemo;
    moveDemo = factory();

        // the copy assignment operator is used to copy moveDemo into copyDemo
        // (the move assignment operator is also called, as it is used by
        //  the copy assignment operator's implementation)
    Demo copyDemo;
    copyDemo = moveDemo;
}