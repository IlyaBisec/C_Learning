#include "seven_five.h"

int main7_5()
{
	FractionPart fraction;
	fraction.getData();
	fraction.averageValue();

	return 0;
}

void FractionPart::getData()
{
	FractionPart fraction;
	std::cout << "Input values: \n";
	for (int i = 0; i < fraction.SIZE; i++)
		std::cin >> fraction.m_values[i];
}

void FractionPart::averageValue()
{
	FractionPart fraction;
	double total = 0;

	for (int i = 0; i < fraction.SIZE; i++)
		total += fraction.m_values[i];
	double average = total / fraction.SIZE;

	std::cout << "Average value: "<<average;
}