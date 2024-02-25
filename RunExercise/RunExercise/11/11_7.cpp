#include "11_7.h"


int main11_7()
{
	Stack stack;
	Number n1(6.02f), n2(3.333f), n3(75.25f), n4(2.0f), n5(3.14159f);
	Operator plus('+'), mult('*'), minus('-'), div('/');

	stack.push(&n1); stack.push(&plus); stack.push(&n2);
	stack.push(&mult); stack.push(&n3); stack.push(&plus);
	stack.push(&n4); stack.push(&div); stack.push(&n5);

	while (stack.getTop() > 0) {

		if (stack.isNum())
			std::cout << stack.pop()->getNumber();
		else
			std::cout << stack.pop()->getOperator();

		if (stack.getTop() > 0) std::cout << ' ';
	}
	std::cout << "\n";

	return 0;
}