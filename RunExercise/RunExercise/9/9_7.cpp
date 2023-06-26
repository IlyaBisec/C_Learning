#include "9_7.h"

int main9_7()
{
	CounterPostFix post_alpha;                          
	CounterPostFix post_beta(100);
	std::cout <<"counter 1: " << post_alpha.getCount() << "\n"; // 0
	std::cout << "counter 2: " << post_beta.getCount() << "\n"; // 100

	// Prefix Test
	++post_alpha; ++post_alpha; ++post_alpha;                
	std::cout << "counter 1: " << post_alpha.getCount() << "\n"; // 3

	--post_beta; --post_beta;                  
	std::cout << "counter 2: " << post_beta.getCount() << "\n"; // 98

	CounterPostFix post_cetta = ++post_alpha;
	std::cout << "counter 3: " << post_cetta.getCount() << "\n"; // 4
	std::cout << "counter 1: " << post_alpha.getCount() << "\n"; // 4


	CounterPostFix post_fetta = --post_beta;
	std::cout << "counter 4: " << post_fetta.getCount() << "\n"; // 97
	std::cout << "counter 2: " << post_beta.getCount() << "\n";  // 97

	post_alpha++;                               
	std::cout << "counter 1: " << post_alpha.getCount() << "\n"; // 5

	post_beta--;                                 
	std::cout << "counter 2: " << post_beta.getCount() << "\n"; // 96

	std::cout << "\n";

	return 0;
}

CounterDec CounterDec::operator--()
{
	return CounterDec(--p_Count);
}


unsigned int CounterBase::getCount() const
{
	return p_Count;
}

CounterBase CounterBase::operator++()
{
	return CounterDec(++p_Count);
}

CounterPostFix CounterPostFix::operator--(int)
{
	return CounterDec(p_Count--);
}

CounterPostFix CounterPostFix::operator++(int)
{
	return CounterDec(p_Count++);
}
