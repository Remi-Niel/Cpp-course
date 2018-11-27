#ifndef INCLUDED_SHOWEXCEPTS_
#define INCLUDED_SHOWEXCEPTS_

typedef void (*func)();

class ShowExcepts
{
    int d_number; //?
    func d_thrower;

    public:
        ShowExcepts(int num, func thrower);

        void as_throwlist();
        void as_noexcept();

};
        
inline ShowExcepts::ShowExcepts(int num, func thrower)
:   d_number(num), d_thrower(thrower)
{ }

#endif
