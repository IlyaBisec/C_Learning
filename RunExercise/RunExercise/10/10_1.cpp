#include "10_1.h"


int main10_1()
{
	Pointers pointers;

	pointers.calculateArithmeticMean();

	return 0;
}

void Pointers::calculateArithmeticMean()
{
	do
	{
		if (m_number > m_size){
			cout << "Overflow, max size is "<<m_size<<"\n"; exit(0);
		}

		cout << "Input value: \n";
		cin >> *(m_array + m_number++);
		cout << "Continue(y/n)?";
		cin >> m_choice;

	} while (m_choice != 'n');
	
	for (int i = 0; i < m_number; i++)
		m_total += *(m_array + i);

	m_average = m_total / m_number;
	cout << "Average: " << m_average << "\n";
}
