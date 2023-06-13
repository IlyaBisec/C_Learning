#include "8_8.h"

int main8_8()
{
	NewSafeArray safeArray;
	int upper, lower, down, difference = 0;

	std::cout << "Enter upper limit\n";
	std::cin >> upper;
	std::cout << "Enter lower limit\n";
	std::cin >> lower;

	difference = upper - 100;
	down = lower;

	for (int i = lower - difference;
		i < upper - difference; i++)
	{
		safeArray[i] = (down++) * 10;
	}

	for (int i = lower - difference;
		i < upper - difference; i++)
	{
		int temp = safeArray[i];
		std::cout << "Element " << lower++ << " equal "<< temp <<"\n";
	}

	return 0;
}

int& NewSafeArray::operator[](int index)
{
	if (index < 0 || index > LIMIT)
	{
		std::cout << "Index error\n";
		exit(1);
	}
}
