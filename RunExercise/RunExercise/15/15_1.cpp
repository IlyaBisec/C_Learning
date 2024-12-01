// Sorting float array with help sort() STL

#include "header.h"

int main15_1()
{
	float array_digits[MAX_COUNT];
	int index;
	char answer;

	index = 0;

	do
	{
		std::cout << "Enter float number: ";
		std::cin >> array_digits[index++];
		
		if (index < MAX_COUNT)
		{
			std::cout << "And more? (y/n): ";
			std::cin >> answer;
		}

	} while (answer != 'n' && index < MAX_COUNT);

	// Enter sort algorithm(to up) to float array digits
	std::sort(array_digits, array_digits + index);

	// Output
	std::cout << "Sorted: ";
	for (int i = 0; i < index; i++)
	{
		std::cout << array_digits[i] << ' ';
	}
	std::cout << "\n";

	return 0;
}