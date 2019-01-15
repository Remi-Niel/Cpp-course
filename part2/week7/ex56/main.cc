#include "main.ih"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Program expects 2 arguments\n";
        return 1;
    }

    int hours = stoi(argv[1]);
    int seconds = stoi(argv[2]);

    cout << hours << " hours is ";
    cout << chrono::duration_cast<chrono::minutes>(chrono::hours{hours}).count();
    cout << " minutes\n";

    chrono::minutes mins{chrono::seconds{seconds} / chrono::minutes{1}};
    cout << seconds << " seconds is ";
    cout << mins.count() << " minutes\n";
}