#include "8_10.h"

int main8_10()
{
	Sterling funtOne, funtTwo, sumFunt;
	double decimal;

	std::cout << "Enter decimal pounds: \n";
	std::cin >> decimal;

	funtOne.getSterling();
	funtTwo.getSterling();

	sumFunt = funtOne + funtTwo;
	sumFunt.putSterling();

	sumFunt = funtOne - funtTwo;
	sumFunt.putSterling();

	sumFunt = funtOne * decimal;
	sumFunt.putSterling();

	sumFunt = funtOne / funtTwo;
	sumFunt.putSterling();

	sumFunt = funtOne / decimal;
	sumFunt.putSterling();

	decimal = sumFunt;
	std::cout << decimal << "\n";
}

void Sterling::getSterling()
{
	std::cout << "Enter ponds: ";
	std::cin >> mPounds;

	std::cout << "Enter shillings: ";
	std::cin >> mShilling;

	std::cout << "Enter pens: ";
	std::cin >> mPens;
}

void Sterling::putSterling() const
{
	std::cout << "Result: J" << mPounds << "." << mShilling
		<< "." << mPens << "\n";
}

Sterling Sterling::operator +(Sterling sterling)
{
	int sumPens = (mPounds * 20 * 12 + mShilling * 12 + mPens) +
		(sterling.mPounds * 20 * 12 + sterling.mShilling * 12 + sterling.mPens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator -(Sterling sterling)
{
	int sumPens = (mPounds * 20 * 12 + mShilling * 12 + mPens) -
		(sterling.mPounds * 20 * 12 + sterling.mShilling * 12 + sterling.mPens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator *(double sterling)
{
	int sumPens = (mPounds *20 * 12 + mShilling * 
		12 + mPens)*(sterling);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator /(Sterling sterling)
{
	int sumPens = (mPounds * 20 * 12 + mShilling * 12 + mPens) /
		(sterling.mPounds * 20 * 12 + sterling.mShilling * 12 + sterling.mPens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator /(double sterling)
{
	int sumPens = (mPounds * 20 * 12 + mShilling * 12 + mPens) / (sterling);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling::operator double()
{
	float sum = mPens + mShilling * 12 + (mPounds * 20) * 12;
	double funt = (sum / 2.4) / 100;
	
	return funt;
}
