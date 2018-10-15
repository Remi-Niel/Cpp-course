#include "main.ih"

void inv_identity(int (*square)[10])
{
	//Iterate through all 10 rows
	for (int (*row)[10] = square; row != (square + 10); ++row)
	{
		//Iterate through all 10 columns
		for (int *val = *row, *max = *(row) + 10; val != max; ++val)
			//if col# == row# set to 0 otherwise 1
			*val = (row - square) == (val - *row) ? 1 : 0; 
	}
}