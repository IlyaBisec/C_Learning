// The word is given. Get his last letter. If the word ends with a soft sign, then get the penultimate letter.

#include "../stdafx2.h"

char getLastLetter(const std::string &word)
{
	if(word.empty())
	{
		return '\0';
	}

	if (word.back() == 'm')
		if (word.size() > 1)
			return word[word.size() - 2]; // Return prelast letter
		else
			return '\0'; // If only 'm'

	return word.back();
}

int main1p5()
{
	std::string word;
	std::cout << "Enter a word: ";
	std::cin >> word;

	char lastLetter = getLastLetter(word);

	if (lastLetter != '\0')
		std::cout << "Last letter: " << lastLetter << "\n";
	else
		std::cout << "Word contains only 'm' letter\n";

	return 0;
}