#include "9_10.h"

int main9_10()
{
	Pair p1 = { 23, 56 },
		p2 = { 12, 3 },
		p3 = { 55, 100 },
		p4 = { -100, 555 };

	PairStack pairStack;

	pairStack.push(p1);
	pairStack.push(p2);
	pairStack.push(p3);
	pairStack.push(p4); // Stack overflow

	Pair pair;
	
	pair = pairStack.pop();
	std::cout << pair.x << ", " << pair.y << "\n";

	pair = pairStack.pop();
	std::cout << pair.x << ", " << pair.y << "\n";

	pair = pairStack.pop();
	std::cout << pair.x << ", " << pair.y << "\n";

	// Stack is empty
	pair = pairStack.pop();
	std::cout << pair.x << ", " << pair.y << "\n";

	return 0;
}

void Stack::push(int var)
{
	p_Stack[++p_Top] = var;
}

int Stack::pop()
{
	return p_Stack[p_Top--];
}

void StackChild::push(int var)
{
	if (p_Top >= p_MAX - 1) {
		std::cout << "Stack overflow\n";
		exit(1);
	}

	Stack::push(var);
}

int StackChild::pop()
{
	if (p_Top < 0)
	{
		std::cout << "Stack is empty!\n";
		exit(1);
	}

	return Stack::pop();
}

// Pushing in stack unit from two variables
void PairStack::push(Pair unit)
{
	StackChild::push(unit.x);
	StackChild::push(unit.y);
}

// Poping two variables from unit
Pair PairStack::pop()
{
	Pair temp;

	temp.y = StackChild::pop();
	temp.x = StackChild::pop();

	return temp;
}
