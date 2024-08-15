// Find factorial with help Verylong number
// and test arithmetical funcsions

#include "13_1.h"

int main13_1()
{
	UL number, position;
	Verylong factorial = 1;

	std::cout << "Input number: ";
	std::cin >> number;

	for(position = number; position > 0; position--)
	{
		factorial = factorial * position;
	}
	std::cout << "Factorial: ";
	factorial.put();
	std::cout << "\n";

	Verylong result, digit1, digit2;

	std::cout << "\nEnter the 1st number: ";
	digit1.get();
	std::cout << "\nEnter the 2st number: ";
	digit2.get();

	result = digit1 + digit2;
	std::cout << "Sum: "; result.put();

	result = digit1 - digit2;
	std::cout << "Substruct: "; result.put();

	result = digit1 * digit2;
	std::cout << "Multiplication: "; result.put();

	result = digit1 / digit2;
	std::cout << "Division: "; result.put();

	result = digit1 % digit2;
	std::cout << "The remainder of devision: "; result.put();

	std::cout << "\n";

	return 0;
}