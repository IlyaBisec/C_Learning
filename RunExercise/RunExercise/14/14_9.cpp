#include "14_9.h"

using namespace Template_14_9;

int main14_9()
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
	catch (SafeArray::IndexOut error)
	{
		std::cout << "Uncorrected index "<<error.index<<"\n";
		exit(1);
	}

	return 0;
}