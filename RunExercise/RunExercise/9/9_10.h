#pragma once

// Working with two variables using the
// pairStack class derived from the Stack class

#include "..\stdafx.h"

struct Pair
{
	int x;
	int y;
};

// Base class
class Stack
{
public:
	Stack() { p_Top = -1; }

	void push(int var);
	
	int pop();

protected:
	static const int p_MAX = 7;

	int p_stack[p_MAX];
	int p_Top;
};

class StackChild : public Stack
{
public:
	void push(int var);

	int pop();
};

// For work with two variables
class PairStack : public StackChild
{
public:
	// Pushing in stack unit from two variables
	void push(const Pair &unit);
	// Poping two variables from unit
	Pair pop();
};