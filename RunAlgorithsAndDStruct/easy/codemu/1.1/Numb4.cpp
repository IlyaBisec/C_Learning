// Two words are given. Check that the first letters of these words match.

#include "../stdafx2.h"

int main1p4()
{
	char tempStr[SIZE];

	std::cout << "Enter a string: \n";
	fgets(tempStr, sizeof(tempStr), stdin);

	if(strlen(tempStr) >= SIZE)
	{
		std::cout << "Length string can't be > " << SIZE << std::endl;
		exit(-1);
	}

	// Find 1st word
	char *firstWord = strtok(tempStr, " ");
	// And second word
	char *secondWord = strtok(NULL, " ");

	if (firstWord != NULL && secondWord != NULL && firstWord[0] == secondWord[0])
		std::cout << "Letters equal\n";
	else
		std::cout << "Letters not equal\n";


	return 0;
}