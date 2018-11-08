#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>


int main(int argc, char *argv[])
{
    							// open stream with 'standard' file location
    std::ifstream in("/var/log/account/pacct");
    size_t files = 0;
    size_t aFlag = 0;

    							// check for -a flag
    for (int index = argc - 1; index != 0; --index) 
    {
    	if (argv[index] == std::string("-a"))
    		aFlag = 1;
    }

    if (aFlag && argc == 2)		// catch option where -a is only argument
    	argc = 1;
    							
    while (files != argc)		// continue while there are files to be opened
    {
    	++files;				
	    if (argc != 1)			// if there is more than one file,
	    {						// close last file and open the next one
	        in.close();
	        in.open(argv[files]);
	    }

	    
	    char buffer[64] = {};	// holds one acct v3

	    						// while there is more to read and no flag
	    while (in)				// (-a causes failbit on open, is skipped)
	    {
	        in.read(buffer, 64);

	        					// get exit code (assuming little-endian)
	        uint32_t exitCode = static_cast<uint32_t>
	        (
	            ((buffer[7] & 0xff) << 24) | ((buffer[6] & 0xff) << 16) |
	            ((buffer[5] & 0xff) << 8) | (buffer[4] & 0xff)
	        );

	        					// if not 0, or if -a, print name and code
	        if (exitCode || aFlag)
	        {
	            std::cout << '\'';
	            for (size_t byteNr = 48; byteNr != 64 && buffer[byteNr] != 0; ++byteNr)
	            {
	                std::cout << buffer[byteNr];
	            }
	            std::cout << "\' ";

	            				// for codes 9 and 15, print signal name
	            if (exitCode == 9)
	                std::cout << "KILL";

	            else if (exitCode == 15)
	                std::cout << "TERM";

	            else std::cout << exitCode;

	            std::cout << '\n';
	        }
	    }
	}
}