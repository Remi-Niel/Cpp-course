#include "main.ih"

int main(int argc, char **argv)
{
    if (string{"-b"} == argv[1])   //binary output
    {
        Converter convert{argv[2]};
        convert.binaryOutput(argv[3]);
    }
    else                    //Human readable output
    {
        Converter convert{argv[1]};
        convert.humanReadableOutput(argv[2]);
    }
}
