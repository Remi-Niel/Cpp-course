#include "user.ih"

User::User()
{
    d_groupId = 0;
    d_userId = 0;

    d_valid = parseUserStruct();
}