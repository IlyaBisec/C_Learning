// Контейнеры в прямом и обратном направлении для вектора целых чисел
// с переворачиванием

#include "header.h"

int main15_6()
{
	std::vector<int> vect_integer;
	int number;
	char answer;

	getUserData("integer number", number, vect_integer, answer);

	// Create iterators
	std::vector<int>::iterator front_iter;
	std::vector<int>::reverse_iterator back_iter;

	front_iter = vect_integer.begin(); // End - begin
	back_iter = vect_integer.rbegin(); // Begin - end

	// Swap it
	for (int i = 0; i < vect_integer.size() / 2; i++)
		std::swap(*front_iter++, *back_iter++);

	// Output
	std::cout << "Reverse vector: ";
	for (front_iter = vect_integer.begin(); front_iter != vect_integer.end();
		front_iter++)
	{
		std::cout << *front_iter << ' ';
	}
	std::cout << "\n";

	return 0;
}