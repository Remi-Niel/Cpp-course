#compiling the lib

`icmbuild` //to generate the .o files
cd tmp/o/
ar rvs libdata.a 1display.o 1read.o

#compiling and linking main
c++ -std=c++17 -Wall -Werror -c main.cc
c++ -std=c++17 -Wall -Werror main.o -L. -ldata

#Running it with:
./a.out < data.in

#output
Object 1: value is: 1
Object 2: value is: 2
Object 3: value is: 3
Object 4: value is: 4

#output now becomes:
./a.out
[1]    4475 segmentation fault (core dumped)  ./a.out

# Final step: The output is now this both times.
Object 1: value is: 1
Object 2: value is: 2
Object 3: value is: 3
Object 4: value is: 4