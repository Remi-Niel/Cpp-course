#include "main.ih"

int main(int argc, char **argv)
try
{
    throw Exception{} << "insert anything that's "
            "Ostream-insertable: " << "strings"s << ", values " <<
            argc << " etc., etc.";
}
catch (exception const &ex)
{
    cout << ex.what() << '\n';
}
