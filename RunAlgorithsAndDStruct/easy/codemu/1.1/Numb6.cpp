// Given a number:
// int num = 123;
// to std::string "123"

#include "../stdafx2.h"
#include <string>

int main1p6()
{
	int num = 123;
	std::string str  = std::to_string(num);

	std::cout << str << std::endl;

	return 0;
}
