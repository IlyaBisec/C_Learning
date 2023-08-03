#pragma once

// Using 10 separate arrays as one one-dimensional array, allowing the use
// of array operations. That is, we can access the array elements by writing
// an expression of type a[j] to the main() function, andclass methods
// can access class fields using a two - step approach.

#include "..\stdafx.h"

using namespace std;

// A class representing a single array of 'n' separates arrays
class NumberArrays
{
public:

	NumberArrays(int numberArrays, int maxSize) : 
		m_NUMARRAYS(numberArrays), m_MAXSIZE(maxSize)
	{
		ptr_Ap = new int *[m_NUMARRAYS];

		for (int i = 0; i < m_NUMARRAYS; i++) 
		{
			*(ptr_Ap + i) = new int[m_MAXSIZE];
		}
	}
	~NumberArrays()
	{
		for (int i = 0; i < m_NUMARRAYS; i++)
		{
			delete[] *(ptr_Ap + i);
		}

		// Delete Pointer to an array of pointers to separate arrays
		delete[] ptr_Ap;
	}

	// Overloaded operation[]
	int &operator[](int n);

private:

	const int m_NUMARRAYS; // Number of separate arrays
	const int m_MAXSIZE;   // Number of elements in each of the separate arrays
	int **ptr_Ap;		   // Pointer to an array of pointers to separate arrays
};