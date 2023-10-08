#pragma once

// Using inheritance with postfix
// opertations for cases of decrease
// and increase

#include "..\stdafx.h"

class CounterBase
{
public:
	CounterBase(): p_count(){}
	CounterBase(int counter):p_count(counter){}

	unsigned int getCount() const;

	// Increase
	CounterBase& operator++();

protected:
	unsigned int p_count;
};

class CounterDec : public CounterBase
{
public:

	CounterDec() : CounterBase()
	{}
	CounterDec(int counter): CounterBase(counter)
	{}
	// Decrease
	CounterDec& operator--();
};

class CounterPostFix : public CounterDec
{

public:
	CounterPostFix() : CounterDec()
	{}
	CounterPostFix(int counter) : CounterDec(counter)
	{}
	// From CounterDec -> CounterPostFix
	CounterPostFix(const CounterDec &counterDec) : CounterDec(counterDec.getCount())
	{}
	// From CounterBase -> CounterPostFix 
	CounterPostFix(const CounterBase &counterBase)
		: CounterDec(counterBase.getCount())
	{}

	// Postfix
	CounterPostFix operator--(int);
	// Increase
	CounterPostFix operator++(int);

	using CounterDec::operator++;
	using CounterDec::operator--;
};