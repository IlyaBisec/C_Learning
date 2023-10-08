// Overloaded calculator

#pragma once

#include "..\stdafx.h"

class NewFraction
{
public:
    NewFraction() :m_numerator(0), m_denominator(0)
    {}
    NewFraction(int numerator, int denominator) : m_numerator(numerator),
        m_denominator(denominator)
    {}

    void getFraction();
    void lowTerms();
    void displayFraction()const
    {
        std::cout << m_numerator << "/" << m_denominator << std::endl;
    };

    NewFraction operator + (const NewFraction &fraction) const;
    NewFraction operator - (const NewFraction &fraction) const;
    NewFraction operator * (const NewFraction &fraction) const;
    NewFraction operator / (const NewFraction &fraction) const;

private:
    int m_numerator, m_denominator;
};
