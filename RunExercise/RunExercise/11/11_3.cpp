#include "11_3.h"

using namespace chapter_11;

int main11_3()
{
	const int SIZE = 10;
	chapter_11::OwnArray ownArray(SIZE);

	for (int j = 0; j < SIZE; j++)
		ownArray[j] = j * j;

	std::cout << "array 1 = ";
	ownArray.display();
	std::wcout << std::endl;

	// Copy Constructor test
	chapter_11::OwnArray array2(ownArray);
	std::cout << "array 2 = ";
	ownArray.display();
	std::wcout << std::endl;

	// arr==arr test
	chapter_11::OwnArray array_3(10), array_4(5), array_5(15);
	array_3 = ownArray; // With an equal number of elements
	array_4 = ownArray; // The number of elements in the assigned array is greater
	array_5 = ownArray; // The number of elements in the assigned array is less

	std::cout << "array_3 = ";
	array_3.display();
	std::cout << std::endl;
	std::cout << "array_4 = ";
	array_4.display();
	std::cout << std::endl;
	std::cout << "array_5 = ";
	array_5.display();
	std::cout << std::endl;

	// Assign a value to ourselves, array1==array1
	ownArray = ownArray;

	std::cout << "ownArray = ";
	ownArray.display();
	std::cout << std::endl;

	// Multiple assignment
	chapter_11::OwnArray array_6, array_7;
	array_7 = array_6 = ownArray;

	std::cout << "array_6 = ";
	array_6.display();
	std::cout << std::endl;
	std::cout << "array_7 = ";
	array_7.display();
	std::cout << std::endl;

	return 0;
}