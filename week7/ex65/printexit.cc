#include "main.ih"

void print_exit(acct_v3 const &acct)
{
    cout << "'" << acct.ac_comm << "' ";

    switch (acct.ac_exitcode)
    {
        case 9:
            cout << "KILL";
        break;

        case 15:
            cout << "TERM";
        break;

        default:
            cout << acct.ac_exitcode;
        break;
    }

    cout << "\n";
}