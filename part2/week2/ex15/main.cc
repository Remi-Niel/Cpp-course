#include "main.ih"

// Display function, shows how the exceptions work.
void throw_test(func thrower, bool throwlist)
{
    ShowExcepts show(42, thrower);
    try
    {
        if (throwlist)
            show.as_throwlist();
        else
            show.as_noexcept();

        cout << "All good!\n";
    }
    catch(int exception)
    {
        std::cout << "Caught int: " << exception << "\n";
    }
    catch(bad_exception const &exception)
    {
        std::cout << "Caught bad exception!\n";
    }
}

int main(int argc, char **argv)
{   
    cout << "Exhibit 1:\n";
    // shows effect of throwing an int in the throwlist function.
    throw_test([](){ throw 5; }, true);
    
    cout << "Exhibit 2:\n";
    // shows effect of throwing a double in the throwlist function.
    throw_test([](){ throw 1.0; }, true);

    cout << "Exhibit 3:\n";
    // shows effect of throwing something in the noexcept function.
    throw_test([](){ throw "no throw"; }, false);
}
