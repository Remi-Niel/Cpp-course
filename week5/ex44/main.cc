#include "main.ih"

int main(int argc, char **argv)
{
	int square[10][10];

	int *row[10];

	for (size_t idx = 0; idx != 10; ++idx)
		row[idx]= square[idx];

	inv_identity(row);
}

