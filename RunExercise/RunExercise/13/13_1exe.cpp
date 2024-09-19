// Find factorial with help Verylong number
// and test arithmetical funcsions

#include "13_1.h"
#include <io.h>
#include <fcntl.h>


int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	unsigned long number, j;
	Verylong factorial = 1;          

	wcout << L"Input number: ";
	wcin >> number;

	for (j = number; j > 0; j--)
		factorial = factorial * j;
	wcout << L"Factorial = ";
	factorial.put();
	wcout << endl;

	// TESTING

	Verylong s, s1, s2;

	wcout << L"\nEnter the first number: "; s1.get();
	wcout << L"Enter the second number: "; s2.get();
	s = s1 + s2;
	wcout << L"\nSumm: "; s.put();
	s = s1 - s2;
	wcout << L"\nSubstruct: "; s.put();
	s = s1 * s2;
	wcout << L"\nMultiplication: "; s.put();
	s = s1 / s2;
	wcout << L"\nDivision: "; s.put();
	s = s1 % s2;
	wcout << L"\nRemainder of the division: "; s.put();
	wcout << endl;

	return 0;
}


