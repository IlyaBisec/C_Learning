#include "14_1.h"
using namespace Template_14_1;

int main14_1()
{
	// Int
	int iArray[] = { 1, -2, 3, -4, 5 };
	std::cout << average(iArray, 5) << "\n";

	// Long
	long lArray[] = { 1L, -2L, 3L, -40L, 50L };
	std::cout << average(lArray, 5) << "\n";

	// Double
	double dArray[] = { 1.1, -2.9, 3.3, -4.0, 5.4 };
	std::cout << average(dArray, 5) << "\n";

	// Char
	char cArray[] = "TESt";
	std::cout << average(cArray, 4);
	std::cout << " symbol code " << (int)average(cArray, 4)<<"\n";

	return 0;
}