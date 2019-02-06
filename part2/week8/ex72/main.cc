#include "main.ih"

int main(int argc, char **argv)
try
{
    Option::instance().initialize(argc, argv);

    Producer producer{argv[1]};
    producer.run();

}
catch (...)
{
    return 1;
}
