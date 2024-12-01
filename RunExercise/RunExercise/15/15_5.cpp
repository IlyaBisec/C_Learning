// combining containers(an array with even numbers and a set with odd numbers)
// using the merge() algorithm

#include "header.h"

constexpr int EVEN_SIZE = 11;	// The size of an array with even numbers
constexpr int ODD_SIZE = 8;	// The size of an array with odd numbers
constexpr int EVEN_BEGIN = -6; // The first number of the range of even numbers 
constexpr int ODD_BEGIN = -5;   // The first number of the range of odd numbers


int main15_5()
{
	// Filling an array with even numbers
	int even_arr[EVEN_SIZE];
	for (int i = 0; i < EVEN_SIZE; i++)
		even_arr[i] = EVEN_BEGIN + 2 * i;

	// Creating a multiset and filling it with odd numbers
	std::set<int> odd_multi;
	for (int i = 0; i < ODD_SIZE; i++)
		odd_multi.insert(ODD_BEGIN + 2 * i);

	std::vector<int> mergeVector(EVEN_SIZE + ODD_SIZE);

	// Merging an array and a set into a vector 
	std::merge(even_arr, even_arr + EVEN_SIZE, odd_multi.begin(), odd_multi.end(),
		mergeVector.begin());

	// Output
	std::cout << "Content of vector: " << mergeVector.size();
	std::cout << "\nElements: ";
	for(int i = 0; i < mergeVector.size(); i++)
		std::cout << mergeVector[i] << ' ';

	std::cout << "\n";

	return 0;
}