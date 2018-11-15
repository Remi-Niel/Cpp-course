#include "user.ih"

#include <pwd.h>
#include <sys/types.h>

bool User::parseUserStruct()
{
    passwd *data = getpwent();

    if(!data)
        return false;

    d_name = string(data->pw_name);
    d_userId = data->pw_uid;
    d_groupId = data->pw_gid;
    d_realName = string(data->pw_gecos);
    d_homeDir = string(data->pw_dir);
    d_shell = string(data->pw_shell);
    
    return true;
}