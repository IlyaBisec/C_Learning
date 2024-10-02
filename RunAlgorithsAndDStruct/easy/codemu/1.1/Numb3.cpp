// A string is given. Print the last character of the string to the console.

#include "../stdafx2.h"

int main1p3()
{
	char tempStr[SIZE];

	std::cout << "Input string: \n";
	std::cin >> tempStr;


	if(strlen(tempStr) >= SIZE)
	{
		std::cout << "Length string can't be > " << SIZE << std::endl;
		exit(-1);
	}

	std::cout << "Last character: " << tempStr[strlen(tempStr) - 1] << std::endl;


	return 0;
}