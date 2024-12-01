// Regular forward and reverse iterators for a list of integers
// with inversion

#include "header.h"

int main15_3()
{
	std::list<int> list;
	int number;
	char answer;
	std::string string = "integer number";

	getUserData(string, number, list, answer);
	
	// Create iterators
	std::list<int>::iterator front_iter, back_iter;
	front_iter = list.begin();
	back_iter  = list.end();

	// Swap elements
	int count = 0;
	while (count++ < list.size() / 2)
	{
		std::swap(*front_iter++, *--back_iter);
	}

	
	std::cout << "Reversed list: ";
	for (front_iter = list.begin(); front_iter != list.end(); front_iter++)
		std::cout << *front_iter <<' ';
	std::cout << "\n";



	return 0;
}