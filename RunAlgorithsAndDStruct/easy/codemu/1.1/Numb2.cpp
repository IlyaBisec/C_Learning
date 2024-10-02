// A string is given. Print the length of this line to the console.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

constexpr int SIZE = 80;

int main1p2()
{
	char tempStr[SIZE];

	std::cout<<"Input string: \n";
	std::cin >> tempStr;

	if(strlen(tempStr) > SIZE)
	{
		std::cout << "Length string can't be > " << SIZE << std::endl;
		exit(-1);
	}

	std::cout<<"String length: "<<strlen(tempStr);

	return 0;
}