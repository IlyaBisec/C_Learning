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
	if (index < 0 || index > LIMIT - 1)
	{
		// alert
		std::cout << "Overflow array \n";
		// or close app 
	}
	mArray[index] = indexValue;
}

int SafeArray::getel(int index)
{
	if (index < 0 || index > LIMIT - 1)
	{
		// alert
		std::cout << "Overflow array \n";
		// or close app 
	}

	return mArray[index];
}
