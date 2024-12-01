// A program that allows you to copy sequences inside a container
// let's say the user enters values first1, last1 and first2.
// Checking the program that the sequence overlapping the other is shifted to the left,
// and not to the right. (For example, you can shift some data from position
// 10 to position 9, but not to position 11).

#include "header.h"


int main15_8()
{
	int numbers[SIZE]; // 80
	// Filling
	for (int i = 0; i < SIZE; i++)
		numbers[i] = i;

	// Output befor copy
	std::cout << "Content of array: ";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << numbers[i] << ((i == SIZE - 1) ? '\n' : ' ');
	}

	// Get 3 indexes of array from user
	// first1 and last1 - define the sequence to be copied
	// first2 - It determines the beginning of the place to which the copy will be made

	int first1, last1, first2;

	std::cout << "Enter first1, last1 and first2 (with space): ";
	std::cin >> first1 >> last1 >> first2;

	// Check first1 & last1
	if (first1 < 0 || first1 >= SIZE)
	{
		std::cout << "first1 can only be in the range 0.." << SIZE - 1 << "\n";
		exit(1);
	}
	if (last1 < 0 || last1 >= SIZE)
	{
		std::cout << "last1 can only be in the range 0.." << SIZE - 1 << "\n";
		exit(1);
	}
	if (first1 > last1)
	{
		std::cout << "first1 cannot be greater last1" << SIZE - 1 << "\n";
		exit(1);
	}

	// Check first2
	if (first2 == first1)
	{
		std::cout << "There is no point in copying to the same location\n";
		exit(1);
	}

	// The length of the sequence being copied
	int length = last1 - first1;

	if ((first2 < 0 - length) || (first2 >= SIZE))
	{
		std::cout << "With this first2, the sequence will be outside the array\n";
		exit(1);
	}
	if (first2 < 0)
	{
		first1 = first1 - first2;
		first1 = 0;
		std::cout << "first2 is outside the array limit, the copying will be partial\n";
	}
	if (first2 + length >= SIZE)
	{
		last1 = first1 + (SIZE - 1 - first2);
		std::cout << "first2 is outside the array limit, the copying will be partial\n";
	}

	// Copying
	std::copy(numbers + first1, numbers + last1 + 1, numbers + first2);

	// Output
	std::cout << "Content of array: ";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << numbers[i] << ((i == SIZE - 1) ? '\n' : ' ');
	}

	return 0;
}
