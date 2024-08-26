#include "14_5.h"
#include <iostream>

using namespace Template_14_5;

int main14_5()
{
	int iarr[] = { 1, 2, 3, 4, 0, -3, 10 };
	std::cout << amax(iarr, 7) << "\n";

	double darr[] = { 1.2, 2.2, 3.1, 4.5, 0.4, -3.19, 10.1 };
	std::cout << amax(darr, 7) << "\n";

	char carr[] = "Template is it template";
	std::cout << amax(carr, 24) << " ";
	std::cout << (int) amax(carr, 24) << "\n";

	return 0;
}