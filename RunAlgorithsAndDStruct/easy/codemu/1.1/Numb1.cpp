// A number is given. Check if it is negative or not. Output this information to the console.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

constexpr int SIZE = 80;

int main1p1()
{

	char string[SIZE];

	printf("Input a number: ");
	scanf("%s", &string);

	if (string[0] == '-')
		printf("This number is negative! \n");
	else
		printf("This number is positive! \n");

	return 0;
}