#include "main.ih"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Program expects an argument\n";
        return 1;
    }

    string input(argv[1]);

    char type = input.back();   //Get time unit
    input.pop_back();          //Remove type from str

    auto now = chrono::system_clock::now();

    switch (type)
    {
        case 's':
            now = now + chrono::seconds(stoi(input));
            cout << "seconds\n";
            break;
        case 'm':
            now = now + chrono::minutes(stoi(input));
            cout << "minutes\n";
            break;
        case 'h':
            now = now + chrono::hours(stoi(input));
            cout << "hours\n";
            break;
    };
    
    time_t time = chrono::system_clock::to_time_t(now);

    cout << put_time(localtime(&time), "%H:%M:%S:");
}