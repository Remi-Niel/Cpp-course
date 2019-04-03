#ifndef __INCLUDED_RULES_H
#define __INCLUDED_RULES_H

#include <stdexcept>
#include <string>
#include <vector>
#include <map>

#include <iostream>

class Rules
{
    std::string d_name;
    std::vector<std::string> d_rules;

    public:
        void set_name(std::string const &name);
        void append_rule(std::string const &rule);

        void print() const;
};

// since the rules are returned by the grammar before the identifier
// we set the name after the rules are loaded.
inline void Rules::set_name(std::string const &name)
{
    d_name = name;
}

inline void Rules::append_rule(std::string const &rule)
{
    d_rules.push_back(rule);
}

inline void Rules::print() const
{
    for (std::string const &line : d_rules)
        std::cout << d_name << " = " << line << "\n";
}

#endif