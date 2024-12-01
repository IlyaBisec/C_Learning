// Algorithm sort() for sort array of words 
// push back() - add new words
// operators[] and size() - for the output

#include "header.h"


int main15_2()
{
	std::vector<std::string> words;
	std::string word;
	std::string string = "word";

	char answer;

	getUserData(string, word, words, answer);

	// Enter sort algorithm(to up) to float array digits
	std::sort(words.begin(), words.end());

	// Output
	std::cout << "Sorted: ";
	for (int i = 0; i < words.size(); i++)
	{
		std::cout << "\n" << words[i];
	}
	std::cout << "\n";

	return 0;
}