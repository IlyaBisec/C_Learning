#include "seven_seven.h"

#include "..\stdafx.h"

int main7_7()
{
	SafeArray safeArray;
	int tempValue = 12345;

	safeArray.putel(7, tempValue);
	tempValue = safeArray.getel(7);

	std::cout << tempValue; // 12345

	return 0;

}

void SafeArray::putel(int index, int indexValue)
{
	checkOverflow(index);
	m_array[index] = indexValue;
}

int SafeArray::getel(int index) const
{
	checkOverflow(index);
	return m_array[index];
}

void SafeArray::checkOverflow(int index) const
{
	if (index < 0 || index > LIMIT - 1)
	{
		std::cout << "Overflow array \n";
		exit(1);
	}
}
