#include "task.ih"

void Task::operator()(char const *file)
{
    std::ifstream fs{file};
    while (!fs.eof() && fs.good())
    {
        if (d_is_function(fs.get()))
            d_count++;
    }
}