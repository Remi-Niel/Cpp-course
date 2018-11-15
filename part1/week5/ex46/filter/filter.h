#ifndef INCLUDED_FILTER_
#define INCLUDED_FILTER_

#include "../strings/strings.h"


class Filter
{
	Strings d_str;
	string const* d_first_line;
	string const* d_last_line;

    public:
    	Filter();
    	void display();

	private:
		void set_bounds();
};
        
#endif
