#include "vstring.ih"

Vstring::Vstring(std::istream &in)
{
    std::copy(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>(),
                std::inserter(*this, begin()));
}

size_t Vstring::count(CharMap &cmap, bool (*accept)(char, CharMap &))
{
    size_t total = 0;

    std::for_each(begin(), end(),
        [&](std::string str)
        {
            for (auto ch : str)
            {
                if (accept(ch, cmap))
                    ++total;
            }
        });
    
    return total;
}

size_t Vstring::countChar(std::string const &str, CharMap &cmap,
                          bool (*accept)(char, CharMap &))
{
    size_t total = 0;

    std::for_each(str.begin(), str.end(),
        [&](char ch)
        {
            if (accept(ch, cmap))
                ++total;
        });

    return total;
}