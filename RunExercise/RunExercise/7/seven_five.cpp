#include "seven_five.h"

int main5()
{
	const int SIZE = 10;
	double values[SIZE];

	Fraction fraction;

	fraction.getData(values, 10);
	fraction.averageValue(values, 10);


	return 0;
}

void Fraction::getData(double values[], int size)
{
	std::cout << "Input values: \n";
	for (int i = 0; i < size; i++)
		std::cin >> values[i];
}

void Fraction::averageValue(double values[], int size)
{
	double total = 0;

	for (int i = 0; i < size; i++)
		total += values[i];
	double average = total / size;

	std::cout << "Average value: "<<average;
}