#include <iostream>
#include <fstream>
#include <stdint.h>

int main(int argc, char *argv[])
{
    
    std::ifstream in("/var/log/account/pacct");
    if (argc == 2)
    {
        in.close();
        in.open(argv[1]);
    }

    char buffer[64] = {};
    while (in)
    {
        in.read(buffer, 64);

        // check if exit code is 0 or other
        uint32_t exitCode = static_cast<uint32_t>
        (
            ((buffer[7] & 0xff) << 24) | ((buffer[6] & 0xff) << 16) |
            ((buffer[5] & 0xff) << 8) | (buffer[4] & 0xff)
        );

        // if not 0, print information:
        if (exitCode)
        {
            std::cout << '\'';
            for (size_t byteNr = 48; byteNr != 64 && buffer[byteNr] != 0; ++byteNr)
            {
                std::cout << buffer[byteNr];
            }
            std::cout << "\' ";

            // std::cout << ", flags: " << static_cast<int>(buffer[0]) << ", ;
            if (exitCode == 9)
                std::cout << "KILL";

            else if (exitCode == 15)
                std::cout << "TERM";

            else std::cout << exitCode;

            std::cout << '\n';
        }
    }
}