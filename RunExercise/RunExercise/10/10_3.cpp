#include "10_3.h"
#include <iostream>

int main10_3()
{
	const int sizeArr = 7;
	const char* ptr_Array[sizeArr] =
	{ 
		"Monday", "Tuesday",
		"Wednesday", "Thursday",
		"Friday", "Saturday", "Sunday"
	};

	TenThree::Pointers pointers;

	// Sorting(from A to Z) pointers on string 
	pointers.bSort(ptr_Array, sizeArr);

	for (int i = 0; i < sizeArr; i++)
		cout << *(ptr_Array + i) <<"\n";

	return 0;
}

namespace TenThree
{
	void Pointers::bSort(const char **pointer, int n)
	{
		// indexes for new array
		int k, j;

		for (int j = 0; j < n - 1; j++)
			for (int k = j + 1; k < n; k++)
				order(pointer + j, pointer + k); // Sorting elements
	}
	void Pointers::order(const char **string1, const char **string2)
	{
		if (strcmp(*string1, *string2) > 0)
		{
			const char *temp = *string1;
			*string1 = *string2;
			*string2 = temp;
		}
	}
}