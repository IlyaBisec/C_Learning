#include "10_9.h"

int main10_9()
{
	int numArray, sizeArray;

	cout << "Input number of a separate array: ";
	cin >> numArray;
	cout << "Input the number of elements in each of the separate arrays: ";
	cin >> sizeArray;

	// Combining separate arrays into one whole
	NumberArrays arr(numArray, sizeArray);
	
	int i;

	// Filling in the data array
	for (int i = 0; i < numArray * sizeArray; i++)
		arr[i] = i * 10;

	// Output
	for (int i = 0; i < numArray * sizeArray; i++)
		cout << arr[i] << ((i % sizeArray == sizeArray - 1) ? "\n" : " ");

	return 0;
}

int &NumberArrays::operator[](int n)
{
	// Number of a separate array
	int number = n / m_MAXSIZE;
	// Index of an element in a separate array
	int index = n % m_NUMARRAYS;

	return *(*(ptr_Ap + number) + index);
}
