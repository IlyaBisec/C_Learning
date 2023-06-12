#include "seven_ten.h"

int main7_10()
{
	Money money1, money2, moneySum;
	do
	{
		money1.mstold();
		money2.mstold();
		moneySum.madd(money1, money2);
		moneySum.display();

		std::cout << "\nRepeat?(y/n) \n";
		std::cin.get();
	} while (std::cin.get() != 'n');


	return 0;
}

void Money::mstold()
{
	std::cout << "Enter the amount in decimal point. End with a dollar sign \n";
	std::getline(std::cin, mMoneyLine, '$');

	int lineLegth = mMoneyLine.length();
	std::string number;

	for (int i = 0; i < lineLegth; i++)
	{
		if (mMoneyLine[i] != ',' && mMoneyLine[i] != '$')
		{
			number.push_back(mMoneyLine[i]);
		}
		// Interprets a floating point value in a string str
		number = std::stold(number);
	}
}

void Money::madd(Money money1, Money money2)
{
	mNumber = money1.mNumber + money2.mNumber;
}

void Money::display() const
{
	// write floating-point values in fixed-point notation.
	std::cout << std::setiosflags(std::ios::fixed)
		// Following the decimal point, as many 
		// digits as necessary are written to match
		<< std::setiosflags(std::ios::showpoint)
		// When used in an expression out << setprecision(n) 
		// or in >> setprecision(n), sets the precision parameter 
		// of the stream out or in to exactly n
		<< std::setprecision(2)
		<< "\n" << mNumber << '$' << std::endl;
}