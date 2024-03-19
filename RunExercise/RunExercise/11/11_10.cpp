#include "11_10.h"

int main11_10()
{
	char unsign;         
	char string[LENGTH];

	std::cout << "Enter arithmetic expression, for example: 2.5+3.0*4/3.148-2.84"
		"\nNumbers can be float or content from float numbers."
		"\nNo use space and ().\n";

	do {
		std::cout << "\nInput expression: ";
		std::cin.get(string, LENGTH);  

		chapter11_10::Express *ptrExpression = new chapter11_10::Express(string);

		ptrExpression->parse();

		std::cout << "Result: "
			<< ptrExpression->solve();

		delete ptrExpression;

		std::cout << "\nAnd more (y/n)? "; std::cin >> unsign;
	} while (unsign == 'y');

	return 0;
}

namespace chapter11_10{

	void Express::parse()
	{
		char choice;
		Token *last_value, *last_sign;

		float unsign;
		Number *ptrNumber;
		Operator *ptrOperator;

		char *ptrCurrent = m_ptrString;

		while (ptrCurrent[0])
		{
			choice = ptrCurrent[0];

			// If digits
			if (choice >= '0' && choice <= '9')
			{
				unsign = std::strtof(ptrCurrent, &ptrCurrent);
				ptrNumber = new Number(unsign);
				m_Stack.push(ptrNumber);
			} 
			else if (choice == '+' || choice == '-' || choice == '*' || choice == '/')
			{
				if (m_Stack.gettop() == 1)
				{
					ptrOperator = new Operator(choice);
					m_Stack.push(ptrOperator);
				} else
				{
					last_value = m_Stack.pop();
					last_sign = m_Stack.pop();

					if ((choice == '*' || choice == '/') &&
						(last_sign->getOperator() == '+' || last_sign->getOperator() == '-'))
					{
						m_Stack.push(last_sign);
						m_Stack.push(last_value);
					} else
					{
						switch (last_sign->getOperator())
						{
							case '+':
								unsign = m_Stack.pop()->getNumber() + last_value->getNumber();
								ptrNumber = new Number(unsign);
								m_Stack.push(ptrNumber);
								break;
							case '-':
								unsign = m_Stack.pop()->getNumber() - last_value->getNumber();
								ptrNumber = new Number(unsign);
								m_Stack.push(ptrNumber);
								break;
							case '*':
								unsign = m_Stack.pop()->getNumber() * last_value->getNumber();
								ptrNumber = new Number(unsign);
								m_Stack.push(ptrNumber);
								break;
							case '/':
								unsign = m_Stack.pop()->getNumber() / last_value->getNumber();
								ptrNumber = new Number(unsign);
								m_Stack.push(ptrNumber);
								break;
							default: std::cout << "\nWtf sign\n"; exit(1);
						}
					}
					Operator *pOperator = new Operator(choice);
					m_Stack.push(pOperator);
				}
				ptrCurrent++;
			} else
			{
				std::cout << "\nWtf arithmetic sign\n"; exit(1);
			}
		}
	}

	float Express::solve()
	{
		Token *value;

		float unsign;
		Number *ptrNumber;

		while (m_Stack.gettop() > 1)
		{
			value = m_Stack.pop();
			switch (m_Stack.pop()->getOperator())
			{
				case '+':
					unsign = m_Stack.pop()->getNumber() + value->getNumber();
					ptrNumber = new Number(unsign);
					m_Stack.push(ptrNumber);
					break;
				case '-':
					unsign = m_Stack.pop()->getNumber() - value->getNumber();
					ptrNumber = new Number(unsign);
					m_Stack.push(ptrNumber);
					break;
				case '*':
					unsign = m_Stack.pop()->getNumber() * value->getNumber();
					ptrNumber = new Number(unsign);
					m_Stack.push(ptrNumber);
					break;
				case '/':
					unsign = m_Stack.pop()->getNumber() / value->getNumber();
					ptrNumber = new Number(unsign);
					m_Stack.push(ptrNumber);
					break;
				default: std::cout << "\nnWtf sign\n"; exit(1);
			}
		}

		return m_Stack.pop()->getNumber(); // в стеке осталс€ результат вычислени€ выражени€,
	}
}
