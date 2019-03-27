#ifndef __INCLUDES_H
#define __INCLUDES_H

#include <string>
#include <vector>


struct Rule
{
    std::string lhs;
    std::vector<std::string> rhs;
};

typedef std::vector<Rule> Rules;

#endif