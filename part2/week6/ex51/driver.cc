#include "vstring.ih"

bool vowels(char c, Vstring::CharMap &cmap)
{
    if (std::string("aeiuoAEIOU").find(c) != std::string::npos)
    {
        ++cmap[c];
        return true;
    }
    return false;
}

int main()
{
    Vstring vstring{std::cin};
    Vstring::CharMap vmap;

    std::cout << "Vowels: " << vstring.count(vmap, vowels) << '\n';

    std::for_each(vmap.begin(), vmap.end(),
        [](std::pair<char, size_t> value)
        {
            std::cout << value.first << ": " << value.second << '\n';
        });
}