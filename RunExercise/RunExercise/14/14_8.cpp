#include "14_8.h"

using namespace Template_14_8;

int main14_8()
{
	try
	{
		SafeArray safe;
		safe[0] = 20;
		safe[1] = -20;
		safe[2] = 10;

		int temp;
		temp = safe[0];

		std::cout << "int: " << temp << " " << safe[1] << " " << safe[2] << "\n";
	}
	catch (SafeArray::IndexOut)
	{
		std::cout << "Uncorrected index\n";
		exit(1);
	}

	return 0;
}