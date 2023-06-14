// Finding the largest element
// of the array

#include "..\stdafx.h"

int main7_4()
{
	void maxInt(int* values, int size); // prototype

	int arrayOfValues[5];

	std::cout << "Input values: \n";
	for (int i = 0; i < 5; i++)
		std::cin >> arrayOfValues[i];

	maxInt(arrayOfValues, 5);

	return 0;
}

void maxInt(int *values, int size)
{
	
	values[size];
	int maxValue = values[0];
	
	for (int i = 0; i < size; i++)
		if (values[i] > maxValue)
			maxValue = values[i];

	std::cout << "max value of array: "<<maxValue;
}