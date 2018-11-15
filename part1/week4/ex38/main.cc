#include "main.ih"

int main(int argc, char **argv)
{
	Memory mem;
	CPU cpu(mem);
	cpu.run();
}


