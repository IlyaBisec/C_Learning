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
		if (m_Number > m_Size){
			cout << "Overflow, max size is "<<m_Size<<"\n"; exit(0);
		}

		cout << "Input value: \n";
		cin >> *(m_Array + m_Number++);
		cout << "Continue(y/n)?";
		cin >> m_Choice;

	} while (m_Choice != 'n');
	
	for (int i = 0; i < m_Number; i++)
		m_Total += *(m_Array + i);

	m_Average = m_Total / m_Number;
	cout << "Average: " << m_Average << "\n";
}
