#include "msg.ih"

char const *MsgNames[] = 
{
    "NONE",
    "DEBUG",
    "INFO",
    "NOTICE",
    "WARNING",
    "ERR",
    "CRIT",
    "ALERT",
    "EMERG",
    "ALL"
};

void show(Msg value)
{
    for (size_t idx = 0; idx != 8; ++idx)
    {
        Msg current = static_cast<Msg>(1 << idx);

        if ((value & current) == current)
            cout << MsgNames[idx + 1] << " ";
    }
    cout << "\n";
}