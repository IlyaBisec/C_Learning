#include "9_7.h"

//ch

int main()
{
	int i = 10;
	//int j = (--i * (++i)) + (--(++(i)));
	//int j = (--(--i))++;
	//int j = (--(++i))++;
	//j = (++(++i))--;

	int j = --i;
	j = (++i)--;
	j = ++i - i++;

	std::cout << i << "\n";
	std::cout << j << "\n";

	CounterDec �1(10);                          
	CounterPostFix �2((--�1).getCount());

	std::cout << �1.getCount() << "\n";
	std::cout << �2.getCount() << "\n";
	

	std::cout << "\n";

	return 0;
}

CounterDec &CounterDec::operator--()
{
	--p_count;
	return (*this);
}


unsigned int CounterBase::getCount() const
{
	return p_count;
}

CounterBase &CounterBase::operator++()
{
	CounterDec counretDec;
	++counretDec;
	return (*this);
	//return CounterDec(++p_Count);

}

CounterPostFix CounterPostFix::operator--(int)
{
	CounterPostFix counter;
	--(*this);
	return counter;
}

CounterPostFix CounterPostFix::operator++(int)
{
	CounterPostFix counter;
	++(*this);
	return counter;
}
