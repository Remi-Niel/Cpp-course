#include "strings.ih"

void Strings::iterate(char **environLike)
{
    for (size_t iter = 0; iter != d_nIter; ++iter)
    {
        delete[] d_str;
        d_size = 0;
	    d_str = {};

        for(size_t idx = 0; idx != length(environLike); ++idx)
            add(environLike[idx]);
    }

    cout << d_str[0] << ' ' << d_str[d_size - 1] << '\n';
}
