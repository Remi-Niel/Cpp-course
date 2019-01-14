#include "main.ih"

void print_dots(bool &done)
{
    while(!done)
    {
        cout << "." << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }
    cout << "\n";
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "Needs 1 integer parameter.\n";
        return 1;
    }

    size_t requested = stoi(argv[1]);

    moment start = chrono::system_clock::now();
    
    bool done = false;
    std::thread ticker{print_dots, std::ref(done)};

    vector<size_t> primes;
    primes.reserve(requested);

    primes.push_back(2);
    size_t next = 3;

    while (primes.size() != requested)
    {
        bool divisible = false;
        for (size_t prime : primes)
        {
            if (next % prime == 0)
            {
                divisible = true;
                break;
            }
        }

        if (!divisible)
            primes.push_back(next);
        ++next;
    }

    done = true;
    ticker.join();

    for (size_t prime : primes)
        cout << prime << " ";
    cout << "\n\n";

    moment end = chrono::system_clock::now();

    std::time_t printable = std::chrono::system_clock::to_time_t(start);
    cout << "Starting time: " << ctime(&printable);
    printable = std::chrono::system_clock::to_time_t(end);
    cout << "Ending time:   " << ctime(&printable);

    cout << "Computation of " << requested << " primes took ";
    cout << chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << " seconds\n";
}