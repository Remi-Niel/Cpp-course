#ifndef INCLUDED_VECTORWRAPPER_
#define INCLUDED_VECTORWRAPPER_

#include <vector>
#include <string>

class VectorWrapper
{

    std::vector<std::string> d_strings;

    public:
        size_t size() const;
        size_t capacity() const;
        
        void swap(VectorWrapper &other);
        void operator+=(std::string str);
    private:
};

inline size_t VectorWrapper::size() const
{
    return d_strings.size();
}

inline size_t VectorWrapper::capacity() const
{
    return d_strings.capacity();
}


inline void VectorWrapper::operator+=(std::string str)
{
    d_strings.push_back(str);
}

        
#endif
