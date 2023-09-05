// Overloaded calculator

#pragma once

#include "..\stdafx.h"

class NewFraction
{
public:
    NewFraction() :m_Numerator(0), m_Denominator(0)
    {}
    NewFraction(int numerator, int denominator) : m_Numerator(numerator),
        m_Denominator(denominator)
    {}

    void getFraction();
    void lowTerms();
    void displayFraction()const
    {
        std::cout << m_Numerator << "/" << m_Denominator << std::endl;
    };

    NewFraction operator + (const NewFraction &fraction) const;
    NewFraction operator - (const NewFraction &fraction) const;
    NewFraction operator * (const NewFraction &fraction) const;
    NewFraction operator / (const NewFraction &fraction) const;

private:
    int m_Numerator, m_Denominator;
};
