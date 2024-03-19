#pragma once
#include "../stdafx.h"
#include <io.h> 

class Token
{
public:
	virtual float getNumber() const = 0;
	virtual char  getOperator() const = 0;
};

class Operator : public Token
{
public:
	Operator(char oper) : m_oper(oper) {}; 

	char  getOperator() const { return m_oper; }; 
	float getNumber() const { return 0.0f; }; 

private:
	char m_oper; // +, -, *, / operators
};

class Number : public Token
{
public:
	Number(float num) : m_fnum(num) {}

	float getNumber() const { return m_fnum; }; 
	char  getOperator() const { return '0'; }; 

private:
	float m_fnum; // Number
};

class Stack
{
public:
	Stack() { m_top = 0; };
	
	void push(Token *value) { m_token[++m_top] = value; }

	Token *pop() { return m_token[m_top--]; }
	int   getTop() const { return m_top; }

	bool isNum()const
	{
		Number *ptr_number;
		if(ptr_number = dynamic_cast<Number*>(m_token[m_top]))
		{
			return 1;
		}
		else { return 0; }
	}

private:
	Token *m_token[100];

	int m_top;
};