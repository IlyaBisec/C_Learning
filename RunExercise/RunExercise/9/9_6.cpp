#include "9_6.h"

int& SafeArray::operator[](int index)
{
	if (index < 0 || index >= SIZE)
	{
		std::cout << "Input index error\n";
		exit(1);
	}
	return m_Array[index];
}


int& BoundaryDeterminant::operator[](int index)
{
	if (index < m_lowBoundary || index > m_upBoundary)
	{
		std::cout << "Input index error\n";
		exit(1);
	}
	return SafeArray::operator[](index - m_lowBoundary);
}

int main()
{
	int lower, upper;

	std::cout << "Input upper boundary of array: "; std::cin >> upper;
	std::cout << "Input lower boundary of array: "; std::cin >> lower;

	BoundaryDeterminant boundDeterminant(lower, upper);

	// Set values of elements
	for (int i = lower; i <= upper; i++)
		boundDeterminant[i] = i * 10; // Left
	// Show elements
	for (int j = lower; j <= upper; j++)
	{
		int temp = boundDeterminant[j]; // Right
		std::cout << "Element: " << j << " = " << temp << "\n";
	}

	return 0;
}