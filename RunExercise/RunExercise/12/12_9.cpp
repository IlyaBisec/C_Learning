//There is a fraction class from exercise 7 of Chapter 8 and a program
//in main that implements a calculator with four basic
//arithmetic operations (addition, subtraction, multiplication and division) using this class. It is required
//to overload the insert (<<) and extract (>>) operators for this class.

#include "pre12.h"

namespace chapter12_9
{
	class Fraction
	{
	public:
		Fraction(){}
		Fraction(int numerator, int denumerator) : m_numerator(numerator), 
			m_denumerator(denumerator){}
		
		void getFraction();
		void show() const;
		void lowTerms();

		Fraction operator + (const Fraction &fraction) const;
		Fraction operator - (const Fraction &fraction) const;
		Fraction operator * (const Fraction &fraction) const;
		Fraction operator / (const Fraction &fraction) const;

		bool operator== (const Fraction &fraction) const;
		bool operator!= (const Fraction &fraction) const;

		friend std::ifstream &operator>>(std::ifstream &stream, Fraction &fraction);
		friend std::ofstream &operator<<(std::ofstream &stream, Fraction &fraction);

	private:
		int m_numerator;
		int m_denumerator;

		char m_slash = '/';
	};

	void Fraction::getFraction()
	{
		std::cout << "Enter an ordinary fraction (in the numerator/denominator format): ";
		std::cin >> m_numerator >> m_slash >> m_denumerator;
	}
	void Fraction::show() const
	{
		std::cout << "Result: " << m_numerator << '/' << m_denumerator << "\n";
	}

	// To reduce the fraction to an irreducible form
	void Fraction::lowTerms()
	{
		long numerator, denominator, temp, greatCommonDivisor;

		// Using non-negative values 
		numerator = labs(m_numerator);           
		denominator = labs(m_denumerator);

		if (denominator == 0)   // Check denominator          
		{
			std::cout << "Invalid value \n"; exit(1);
		}
		else if (numerator == 0)     // Check numerator 
		{
			numerator = 0; denominator = 1; return;
		}
		while (numerator != 0)
		{
			// If numerator > denominator
			if (numerator < denominator)
			{
				temp = numerator; 
				numerator = denominator; 
				denominator = temp;
			} //Swap them

			numerator = numerator - denominator;
		}
		greatCommonDivisor = denominator;  

		// Divide by the greatgest common divisor
		numerator /= greatCommonDivisor;        
		denominator /= greatCommonDivisor;

		m_numerator = numerator;
		m_denumerator = denominator;
	}

	// To add two ordinary fractions
	Fraction Fraction::operator+(const Fraction &fraction) const
	{
		int numerator = m_numerator * fraction.m_denumerator + m_denumerator
        * fraction.m_numerator;
		int denominator = m_denumerator * fraction.m_denumerator;

    
		Fraction temp_fraction(numerator, denominator);
		temp_fraction.lowTerms();
		return temp_fraction;
	}

	// For the difference of two ordinary fractions
	Fraction Fraction::operator-(const Fraction &fraction) const
	{
		 int numerator = m_numerator * fraction.m_denumerator - m_denumerator
        * fraction.m_numerator;
		int denominator = m_denumerator * fraction.m_denumerator;

		Fraction temp_fraction(numerator, denominator);
		temp_fraction.lowTerms();
		return temp_fraction;
	}

	// For the product of two ordinary fractions
	Fraction Fraction::operator*(const Fraction &fraction) const
	{
		int numerator = m_numerator * fraction.m_denumerator;
		int denominator = m_denumerator * fraction.m_denumerator;

		Fraction temp_fraction(numerator, denominator);
		temp_fraction.lowTerms();
		return temp_fraction;
	}

	// To find the quotient of the division
	Fraction Fraction::operator/(const Fraction &fraction) const
	{
		int numerator = m_numerator * fraction.m_denumerator;
		int denominator = m_denumerator * fraction.m_numerator;

		Fraction temp_fraction(numerator, denominator);
		temp_fraction.lowTerms();
		return temp_fraction;
	}

	// Overloading the "equals" comparison operation (==) for ordinary fractions
	bool Fraction::operator==(const Fraction &fraction) const
	{
		if ((m_numerator == fraction.m_numerator) && 
			(m_denumerator == fraction.m_denumerator))
			return true;
		else
			return false;
	}
	
	// Overloading the "not equal" comparison operation (!=) for ordinary fractions
	bool Fraction::operator!= (const Fraction &fraction) const
	{
		if ((m_numerator == fraction.m_numerator)
			&& (m_denumerator == fraction.m_denumerator))
			return false;
		else
			return true;
	}
	
	// Overloading the extraction operator
	std::ifstream &operator>>(std::ifstream &stream, Fraction &fraction)
	{
		char slash = '/';
		stream >> fraction.m_numerator >> slash >> fraction.m_denumerator;
		return stream;
	}

	// Overloading the insertion operator
	std::ofstream &operator<<(std::ofstream &stream, Fraction &fraction)
	{
		stream << fraction.m_numerator << '/' << fraction.m_denumerator;
		return stream;
	}

}


using namespace chapter12_9;

int main12_9()
{
    char userInputOperator;

    Fraction fr1, fr2, fr3; 
	Fraction fr(0, 1);      
	
	std::cout << "To exit the program, enter the value 0/1 for the first and second fractions.\n\n";

	do {
		std::cout << "Enter two ordinary fractions and the operation sign (+, -, *, /) between them,\n"
			"(for example: 1/2 + 3/4): ";
		std::cin >> fr1 >> userInputOperator >> fr2;

		// If the user has entered the fraction 0/1 as both the first and second fractions
		if ((fr1 == fr) && (fr2 == fr))
			break;

		switch (userInputOperator)
		{
		case '+':
			fr3 = fr1 + fr2; std::cout << "Result: " << fr3 << "\n"; break;
		case '-':
			fr3 = fr1 - fr2; std::cout << "Result: " << fr3 << "\n"; break;
		case '*':
			fr3 = fr1 * fr2; std::cout << "Result: " << fr3 << "\n"; break;
		case '/':
			fr3 = fr1 / fr2; std::cout << "Result: " << fr3 << "\n"; break;
		default: std::cout << "Error sign, repeat pls" << "\n";
		}

	} while (true); 

	return 0;
}