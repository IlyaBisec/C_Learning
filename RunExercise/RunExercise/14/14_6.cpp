#include "14_6.h"

using namespace Template_14_6;

int main14_6()
{
	// Int
	SafeArray<int> safeInt;

	safeInt[0] = 2;
	safeInt[1] = 30;
	safeInt[2] = -400;

	int tempInt;
	tempInt = safeInt[0];
	std::cout << "Int: " << tempInt << " " << safeInt[1] << " " << 
		safeInt[2] << " " << "\n";

	// Double
	SafeArray<double> safeDouble;

	safeDouble[0] = -22.2;
	safeDouble[1] = 30.0;
	safeDouble[2] = -400.2;

	double tempDouble;
	tempDouble = safeDouble[0];
	std::cout << "Double: " << tempDouble << " " << safeDouble[1] << " " <<
		safeDouble[2] << " " << "\n";

	// Char
	SafeArray<char> safeChar;

	safeChar[0] = 'O';
	safeChar[1] = 'n';
	safeChar[2] = 'e';

	char tempChar;
	tempChar = safeChar[0];
	std::cout << "Char: " << tempChar << " " << safeChar[1] << " " <<
		safeChar[2] << " " << "\n";

	return 0;
}