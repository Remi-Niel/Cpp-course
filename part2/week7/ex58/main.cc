#include "main.ih"

void Handler::shift(ostream &out, string const &text)
{
    string output = text;
    for (size_t idx = 0; idx < text.size(); ++idx)
    {
        out << output << "\n";
        output = output.substr(1) + output[0];
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Expected 2 arguments, an output file and a text\n";
        return 1;
    }
    
    ofstream out{argv[1]};
    
    Handler handler;
    thread runner{&Handler::shift, &handler, std::ref(out), argv[2]};

    thread contained{[&]()
    {
        Handler handler;
        handler.shift(out, argv[2]);
    }};

    runner.join();
    contained.join();
}