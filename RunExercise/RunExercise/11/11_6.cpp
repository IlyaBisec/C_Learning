#include "11_6.h"
#include <sstream>
#include <iomanip>
#include <ios>


long double chapter11_6::bMoney::mstold(const char string[])
{
	char temp[100];
	int index = 0;

	for (int i = 0; i < strlen(string); i++)
	{
		// Get symbol from array
		char symbol = string[i];

		// If the symbol is a digit, add it to the temp line, 
		// else if it is a dot, add it to the temp line, and ignore everything else
		if ((symbol >= '0') && (symbol <= '9'))
		{
			temp[index++] = symbol;
		}
		else if (symbol == '.')
		{
			temp[index++] = symbol;
		}
	}
	temp[index] = '\0';

	char *end;
	m_sum = strtold(temp, &end);

	return m_sum;
}


void chapter11_6::bMoney::ldtoms(char string[])
{
	char temp_string[80];
	std::stringstream stream;

	// Convert a sum number of the long double type to a string, specifying that a non-exponential 
	// type of number is needed and the number of digits after the decimal point should be 2
	stream << std::setiosflags(std::ios::fixed) << std::setprecision(2) << m_sum;
	stream >> temp_string;

	int index = 0, n = 0, temp_index;
	int length = strlen(temp_string);
	char separator = ',';				// The symbol separating the triples of digits (separator)
	string[index++] = '$';				// The first symbol is $

	// the expression (length - 3) means the number of digits of the number
	// without a decimal point and two digits after the dot

	if (length > 6) // If separators are required in the number
	{
		if ((length - 3) % 3 == 2) // If there are two higher digits before the separator,
		{
			string[index++] = temp_string[n++]; // then rewrite the two higher grades
			string[index++] = temp_string[n++];
			string[index++] = separator;		// and enter a separator.
		}
		else if ((length - 3) % 3 == 1) // else, if the highest digit before the separator is one,
		{
			string[index++] = temp_string[n++];	// then rewrite the senior category
			string[index++] = separator;		//  and enter the separator
		}
	}

	// Iterate over the remaining characters in the loop
	for (temp_index = n; temp_index < length - 3; temp_index++)
	{
		string[index++] = temp_string[temp_index];  // let's rewrite the next category
		// after each three digits, insert a separator if
		// only this is not the last three categories
		if (((temp_index - n + 1) % 3 == 0) && (temp_index != length - 3 - 1))
			string[index++] = separator;
	}

	string[index++] = temp_string[temp_index++]; // let's rewrite the point and two
	string[index++] = temp_string[temp_index++]; // discharge after the point (centers)
	string[index++] = temp_string[temp_index];
	string[index] = '\0';        // we enter the zero character last
}

void chapter11_6::bMoney::getmoney()
{
	char tms[80];
	std::cout << "Enter the amount of money (exmp: '$1,234,567.99'):\n";
	std::cin >> tms;
	mstold(tms);
}

void chapter11_6::bMoney::putmoney()
{
	char tms[80];
	ldtoms(tms);
	std::cout << tms;
}


using namespace chapter11_6;

int main11_6()
{
	chapter11_6::bMoney sum1, sum2;
	// Round down
	sum1 = "$9,414,083.31"; // 083.00
	sum1.putmoney();
	std::cout << "\n";
	sum2 = roundUpTheAmount(sum1);
	sum2.putmoney();
	std::cout << "\n\n";

	// Round up
	sum1 = "$9,414,083.61"; // 084.00
	sum1.putmoney();
	std::cout << "\n";
	sum2 = roundUpTheAmount(sum1);
	sum2.putmoney(); 
	std::cout << "\n";

	return 0;
}