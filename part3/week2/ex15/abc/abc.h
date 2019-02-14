#ifndef __INCLUDED_ABC_H
#define __INCLUDED_ABC_H

class ABC
{
    public:
        virtual ~ABC();

        void interface();

    private:
        virtual void run() = 0;
};

inline void ABC::interface()
{
    run();
}

#endif