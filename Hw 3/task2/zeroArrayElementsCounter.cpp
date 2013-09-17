#include "zeroArrayElementsCounter.h"

int countZeroElements(int* array, int size)
{
	int count = 0;
	for(int i = 0; i < size; i++)
		if (array[i] == 0)
			count++;
	return count;
}

int countZeroElements(int** array, int line, int column)
{
	int count = 0;
	for(int i = 0; i < line; i++)
		for(int k = 0; k < column; k++)
			if(array[i][k] == 0)
				count++;
	return count;
}


