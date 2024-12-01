// Find factorial with help Verylong number
// and test arithmetical funcsions

#include "13_1.h"
#include <io.h>
#include <fcntl.h>


int main13_1()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);

	unsigned long number, j;
	Verylong factorial = 1;          

	try
	{
		wcout << L"Input number: ";
		wcin >> number; // 5

		//number = 'd';		// Unsigned number only
		//number = 'û';		// Unsigned number only
		//number =  0;		// number can be zero
		//number = '-2';	// Unsigned number only
		//number = 89549;	// Max size: 1000

		if (number == 0)
		{
			std::wcout << "Unsigned number only and number can be zero\n";
			exit(-1);
		}
		// If user_input > SIZE
		if (number >= SIZE || number < 0) {
			std::wcout << "Max size: "<<SIZE<<"\n";
			exit(-1);
		}

		for (j = number; j > 0; j--)
			factorial = factorial * j;
		wcout << L"Factorial = ";
		factorial.put(); // 120
		wcout << endl; 

		// SIMPLE TESTING

		Verylong s, s1, s2;

		//s1 = 'd';  // Unccorrect input, pls number only.
		//s2 = '-ô'; // Unccorrect input, pls number only.

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



	} catch (const std::exception &)
	{

	}


	return 0;
}


