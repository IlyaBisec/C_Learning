#include "9_7.h"

//ch

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

	CounterPostFix post_5 = post_alpha++;
	std::cout << "counter 5: " << post_5.getCount() << "\n";	 // 
	std::cout << "counter 1: " << post_alpha.getCount() << "\n"; // 

	CounterPostFix post_6 = post_beta--;
	std::cout << "counter 5: " << post_6.getCount() << "\n";	 //
	std::cout << "counter 1: " << post_beta.getCount() << "\n"; // 


	std::cout << "\n";

	return 0;
}

CounterDec &CounterDec::operator--()
{
	CounterDec counretDec;
	--counretDec;
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
