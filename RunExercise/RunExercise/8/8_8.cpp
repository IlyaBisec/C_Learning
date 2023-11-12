#include "8_8.h"

int main8_8()
{
	int upper, lower, down, difference = 0;

	std::cout << "Enter upper limit\n";
	std::cin >> upper;
	std::cout << "Enter lower limit\n";
	std::cin >> lower;

	NewSafeArray safeArray(lower, upper);

	for (int i = lower; i <= upper; i++)
	{
		safeArray[i] = i * 10;
	}
	// Show elements
	for (int element = lower; element <= upper; element++)
	{
		int temp = safeArray[element];
		std::cout << "Element " << element << " equal " << temp << "\n";
	}

	return 0;
}

int &NewSafeArray::operator[](int index)
{
	if (index < m_lowerBound || index > m_upperBound)
	{
		std::cout << "Index error\n";
		exit(1);
	}
	return m_array[index - m_lowerBound];
}

const int &NewSafeArray::operator[](int index) const
{
	return (const_cast<NewSafeArray &>(*this))[index];
}

