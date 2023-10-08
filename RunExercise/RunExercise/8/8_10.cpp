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

	return 0;
}

void Sterling::getSterling()
{
	std::cout << "Enter ponds: ";
	std::cin >> m_pounds;

	std::cout << "Enter shillings: ";
	std::cin >> m_shilling;

	std::cout << "Enter pens: ";
	std::cin >> m_pens;
}

void Sterling::putSterling() const
{
	std::cout << "Result: J" << m_pounds << "." << m_shilling
		<< "." << m_pens << "\n";
}

Sterling Sterling::operator+(const Sterling &sterling) const
{
	int sumPens = (m_pounds * 20 * 12 + m_shilling * 12 + m_pens) +
		(sterling.m_pounds * 20 * 12 + sterling.m_shilling * 12 + sterling.m_pens);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator-(const Sterling &sterling) const
{
	int sumPens = (m_pounds * 20 * 12 + m_shilling * 12 + m_pens) -
		(sterling.m_pounds * 20 * 12 + sterling.m_shilling * 12 + sterling.m_pens);
	
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator*(double amount) const
{
	int sumPens = (m_pounds *20 * 12 + m_shilling * 
		12 + m_pens) * (amount);
	
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

double Sterling::operator/(const Sterling &quantityTimes) const
{
	int sumPens = (m_pounds * 20 * 12 + m_shilling * 12 + m_pens) /
		(quantityTimes.m_pounds * 20 * 12 +
		quantityTimes.m_shilling * 12 + quantityTimes.m_pens);
	
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling Sterling::operator/(double amount) const
{
	int sumPens = (m_pounds * 20 * 12 + m_shilling * 12 + m_pens) / (amount);
	long pounds = sumPens / (20 * 12);
	int shilling = sumPens % (20 * 12) / 12;
	int pens = sumPens % (20 * 12) % 12;

	return Sterling(pounds, shilling, pens);
}

Sterling::operator double()
{
	float sum = m_pens + m_shilling * 12 + (m_pounds * 20) * 12;
	double funt = (sum / 2.4) / 100;
	
	return funt;
}
