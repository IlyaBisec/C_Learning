#include "10_8.h"

int main10_8()
{
	tenArrays();
	return 0;
}

void tenArrays()
{
	// SiZE = 10
	int a1[SIZE], a2[SIZE], a3[SIZE], a4[SIZE], a5[SIZE],
		a6[SIZE], a7[SIZE], a8[SIZE], a9[SIZE], a10[SIZE];

	// Array of pointers on the arrays
	int *ptr_Ap[] = { a1, a2, a3, a4, a5, a6, a7, a8, a9, a10 };

	// Indexes for accessong array elements
	int j, k;

	// Filling in the data array
	for (j = 0; j < SIZE; j++) 
	{
		for (k = 0; k < SIZE; k++)
		{
			ptr_Ap[j][k] = (j * 10 + k) * 10;
		}
	}

	// Output
	for (j = 0; j < SIZE; j++)
	{
		for (k = 0; k < SIZE; k++)
		{
			/*if (k == SIZE - 1)
			{
				cout << "\n";
			}
			else cout << ' ';*/
			cout << ptr_Ap[j][k] << ((k == SIZE - 1) ? '\n' : ' ');
		}
	}
}
