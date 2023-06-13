#pragma once

#include "..\stdafx.h"

class NewFraction
{
private:
    int mNumerator, mDenominator;
public:
    NewFraction() :mNumerator(0), mDenominator(0)
    {}
    NewFraction(int numerator, int denominator) : mNumerator(numerator),
        mDenominator(denominator)
    {}

    void getFraction();
    void lowTerms();
    void displayFraction()const
    {
        std::cout << mNumerator << "/" << mDenominator << std::endl;
    };

    NewFraction operator + (NewFraction fraction);
    NewFraction operator - (NewFraction fraction);
    NewFraction operator * (NewFraction fraction);
    NewFraction operator / (NewFraction fraction);
};
