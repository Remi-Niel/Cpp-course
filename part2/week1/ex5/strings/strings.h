#ifndef INCLUDED_STRINGS_
#define INCLUDED_STRINGS_

#include <istream>

struct stringsData
{
	std::size_t size;
	std::string **strings;
};

class Strings
{
    friend std::istream &operator>>(std::istream &in, Strings &str);
    friend std::ostream &operator<<(std::ostream &out, Strings &str);
    friend bool operator==(Strings const &str1, Strings const &str2);

	std::size_t d_size;
    std::size_t d_capacity;
	std::string **d_str;

    public:
    	Strings();
        Strings(Strings const &other);
        Strings(Strings &&tmp);
        Strings(int argc, char **argv);
        Strings(char **environ);
        Strings(std::istream &in);
        ~Strings();
        Strings &operator=(Strings const &rvalue);
        Strings &operator=(Strings &&tmp);
        std::size_t size() const;
        std::size_t capacity() const;
        std::string const * const *data() const;
        std::string &operator[](size_t index);
        std::string &at(size_t idx);
        std::string const &operator[](size_t index) const;
      	std::string const &at(size_t idx) const;
        void resize(std::size_t count);
        void reserve(std::size_t n = 0);
        stringsData release();
    	void add(std::string const &str);

    private:
        std::istream &extractFrom(std::istream &in);
        std::ostream &insertInto(std::ostream &out);
        bool equals(Strings const &str) const;
        static size_t length(char **data);
        std::string &at_index(size_t idx) const;
        void swap(Strings &other);
};

inline size_t Strings::size() const
{
    return d_size;
}

inline size_t Strings::capacity() const
{
    return d_capacity;
}

inline std::string const * const *Strings::data() const
{
    return (d_str);
} 

inline std::istream &operator>>(std::istream &in, Strings &str)
{
    return str.extractFrom(in);
}

inline std::ostream &operator<<(std::ostream &out, Strings &str)
{
    return str.insertInto(out);
}

inline bool operator==(Strings const &str1, Strings const &str2)
{
    return str1.equals(str2);
}

inline bool operator!=(Strings const &str1, Strings const &str2)
{
    return !(str1 == str2);   
}
        
#endif
