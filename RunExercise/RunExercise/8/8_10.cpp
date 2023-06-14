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
	std::cin >> m_Pounds;

	std::cout << "Enter shillings: ";
	std::cin >> mShilling;

	std::cout << "Enter pens: ";
	std::cin >> m_Pens;
}

void Sterling::putSterling() const
{
	std::cout << "Result: J" << m_Pounds << "." << mShilling
		<< "." << m_Pens << "\n";
}

Sterling Sterling::operator +(Sterling sterling)
{
	int sumPens = (m_Pounds * 20 * 12 + mShilling * 12 + m_Pens) +
		(sterling.m_Pounds * 20 * 12 + sterling.mShilling * 12 + sterling.m_Pens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator -(Sterling sterling)
{
	int sumPens = (m_Pounds * 20 * 12 + mShilling * 12 + m_Pens) -
		(sterling.m_Pounds * 20 * 12 + sterling.mShilling * 12 + sterling.m_Pens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator *(double sterling)
{
	int sumPens = (m_Pounds *20 * 12 + mShilling * 
		12 + m_Pens)*(sterling);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator /(Sterling sterling)
{
	int sumPens = (m_Pounds * 20 * 12 + mShilling * 12 + m_Pens) /
		(sterling.m_Pounds * 20 * 12 + sterling.mShilling * 12 + sterling.m_Pens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator /(double sterling)
{
	int sumPens = (m_Pounds * 20 * 12 + mShilling * 12 + m_Pens) / (sterling);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling::operator double()
{
	float sum = m_Pens + mShilling * 12 + (m_Pounds * 20) * 12;
	double funt = (sum / 2.4) / 100;
	
	return funt;
}
