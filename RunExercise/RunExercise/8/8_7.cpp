#include "8_7.h"

int main8_7()
{
    char userInputOperator;

    do {
        NewFraction alpha, beta, windetta;
        
        alpha.getFraction();
       
        std::cout << "Enter sign\n";
        std::cin >> userInputOperator;

        beta.getFraction();

        switch (userInputOperator)
        {
        case '+': windetta = alpha + beta;
            break;
        case '-': windetta = alpha - beta;
            break;
        case '*': windetta = alpha * beta;
            break;
        case '/': windetta = alpha / beta;
            break;
        default: std::cout << "Input error\n";
            break;
        }
    
        windetta.lowTerms();
        windetta.displayFraction();

        std::cout << "Continue? (y/n)\n";
        std::cin >> userInputOperator;
    
    } while (userInputOperator != 'n');

    return 0;
}

void NewFraction::getFraction()
{
    char choice;
    std::cout << "Input fraction\n";
    std::cin >> m_numerator >> choice >> m_denominator;
    if (m_numerator == 0 && m_denominator == 0)
    {
        if (m_numerator == 1 && m_denominator == 1)
        {
            if (m_numerator == 0 && m_denominator == 1)
            {
                std::cout << "Error!\n";
                exit(1);
            }
        }
    }
}

void NewFraction::lowTerms()
{
    long numerator, denominator, temp, greatCommonDivisor;

    // using non-negative values 
    numerator = labs(m_numerator);           
    denominator = labs(m_denominator);

    if (denominator == 0)   // check denominator          
    {
        std::cout << "Invalid value \n"; exit(1);
    }
    else if (numerator == 0)     // check numerator 
    {
        numerator = 0; denominator = 1; return;
    }
    while (numerator != 0)
    {
        // if numerator > denominator
        if (numerator < denominator)
        {
            temp = numerator; 
            numerator = denominator; 
            denominator = temp;
        } //swap them

        numerator = numerator - denominator;
    }
    greatCommonDivisor = denominator;  

    // divide by the greatgest common divisor
    numerator /= greatCommonDivisor;        
    denominator /= greatCommonDivisor;
}

NewFraction NewFraction::operator+(const NewFraction &fraction) const
{
    int numerator = m_numerator * fraction.m_denominator + m_denominator
        * fraction.m_numerator;
    int denominator = m_denominator * fraction.m_denominator;
    return NewFraction(numerator, denominator);
}

NewFraction NewFraction::operator-(const NewFraction &fraction) const
{
    int numerator = m_numerator * fraction.m_denominator - m_denominator
        * fraction.m_numerator;
    int denominator = m_denominator * fraction.m_denominator;
    return NewFraction(numerator, denominator);
}

NewFraction NewFraction::operator*(const NewFraction &fraction) const
{
    int numerator = m_numerator * fraction.m_denominator;
    int denominator = m_denominator * fraction.m_denominator;
    return NewFraction(numerator, denominator);
}

NewFraction NewFraction::operator/(const NewFraction &fraction) const
{
    int numerator = m_numerator * fraction.m_denominator;
    int denominator = m_denominator * fraction.m_numerator;
    return NewFraction(numerator, denominator);
}
