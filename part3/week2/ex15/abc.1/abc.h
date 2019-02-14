#ifndef __INCLUDED_ABC_H
#define __INCLUDED_ABC_H

#include <functional>

class ABC
{
    public:
        virtual ~ABC();

        void interface();

        template <class derived, typename ...Params>
        static ABC &&make(Params &&...params);


    private:
        virtual void run() = 0;
};

inline void ABC::interface()
{
    run();
}

template <class derived, typename ...Params>
ABC &&ABC::make(Params &&...params)
{
    derived tmp = derived{std::forward<Params>(params)...};
    return std::move(static_cast<ABC&&>(tmp));
}

#endif