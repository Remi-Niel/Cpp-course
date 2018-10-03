#ifndef INCLUDED_USER_
#define INCLUDED_USER_

#include <string>

class User
{

    bool d_valid;
    size_t d_groupId;
    std::string d_homeDir;
    std::string d_name;
    std::string d_realName;
    std::string d_shell;
    size_t d_userId;

    public:
        User();

        bool valid() const;
        size_t groupId() const;
        std::string homeDir() const;
        bool inGroup(size_t gid) const;
        std::string name() const;
        std::string realName() const;
        std::string shell() const;
        size_t userId() const;

    private:
        bool parseUserStruct();
};

inline bool User::valid() const
{
    return d_valid;
}

inline size_t User::groupId() const
{
    return d_groupId;
}

inline std::string User::homeDir() const
{
    return d_homeDir;
}

inline bool User::inGroup(size_t gid) const
{
    return gid == d_groupId;
}

inline std::string User::name() const
{
    return d_name;
}

inline std::string User::realName() const
{
    return d_realName;
}

inline std::string User::shell() const
{
    return d_shell;
}

inline size_t User::userId() const
{
    return d_userId;
}

#endif
