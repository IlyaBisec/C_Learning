#include "14_7.h"

using namespace Template_14_7;

template <class F>
void Fraction<F>::get()
{
	char slash;
	long tempNum, tempDenum;

	std::cout << "Enter numerator/denumerator ";
	std::cin >> tempNum >> slash >> tempDenum;
	m_numirator = tempNum;
	m_denumirator = tempDenum;
}

template <class F>
void Fraction<F>::display() const
{
	std::cout << "Result: " << (long)m_numirator << "/" << (long)m_denumirator << "\n";
}

template <class F>
Fraction<F> Fraction<F>::lowterms()
{
	long tempNum, tempDenum, temp, greatDivisor;

	tempNum = labs(m_numirator);
	tempDenum = labs(m_denumirator);

	if (tempDenum == 0)
	{
		std::cout << "Error denumirator";
		exit(1);
	}
	else if (tempNum == 0)
	{
		m_numirator = 0;
		m_denumirator = 1;

		return Fraction(m_numirator, m_denumirator);
	}

	// Find greatest common divisor
	while (tempNum != 0)
	{
		// Numerator > denumerator
		if (m_numirator < m_denumirator)
		{
			temp = tempNum;
			tempNum = tempDenum;
			tempDenum = temp;
		}
		tempNum = tempNum - tempDenum;
	}
	greatDivisor = tempDenum;

	m_numirator = m_numirator / greatDivisor;
	m_denumirator = m_denumirator / greatDivisor;

	return Fraction(m_numirator, m_denumirator);
}


int main14_7()
{
	Fraction<char> frac1, frac2, frac3;
	char operand;
	Fraction<char> fraction(0, 1);
	std::cout << "For the exit from program enter 0/1";

	do
	{
		frac1.get();
		std::cout << "Enter sign of operaton (+, -, *, /): ";
		std::cin >> operand;

		frac2.get();

		// If exit
		if ((frac1 == fraction) && (frac2 == frac3))
			break;

		switch (operand)
		{
		case '+':
			frac3 = frac1 + frac2;
			frac3.display();
			break;
		case '-':
			frac3 = frac1 - frac2;
			frac3.display();
			break;
		case '*':
			frac3 = frac1 * frac2;
			frac3.display();
			break;
		case '/':
			frac3 = frac1 / frac2;
			frac3.display();
			break;
		default:
			std::cout << "Uncorrect operation sign! Try more\n";
		}

	} while (true);

	return 0;
}


