#include "main.ih"

int main()
{
    User user;

    cout << "Loading user..  " << (user.valid() ? "success!\n" : "failed!.\n");
    if(!user.valid())
        return -1;

    cout << "User group id: " << user.groupId() << "\n";
    cout << "User homedir: " << user.homeDir() << "\n";
    cout << "Username: " << user.name() << "\n";
    cout << "User real name: " << user.realName() << "\n";
    cout << "User shell: " << user.shell() << "\n";
    cout << "User id: " << user.userId() << "\n";
}

