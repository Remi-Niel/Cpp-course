#include "workforce.h"
#include <iostream>
#include <sstream>

int main()
{
    std::istringstream in{"this is a line\n"};
    WorkForce wf{};
    wf.run(in, std::cout);  // output: "this is a line: processed"
}