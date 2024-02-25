#pragma once
#include "../stdafx.h"
#include <io.h> 

class Token // Абстрактный базовый класс
{
public:
	virtual float getNumber() const = 0; // чистая виртуальная
	// функция
	virtual char getOperator() const = 0;
};
class Operator : public Token
{
public:
	Operator(char oper) : m_oper(oper) {}; // конструктор устанавливает значение
	char getOperator() const { return m_oper; }; // получить значение
	float getNumber() const { return 0.0f; }; // просто некая функция

private:
	char m_oper; // Операторы +, -, *, /
};
class Number : public Token
{
public:
	Number(float num) : m_fnum(num) {}// конструктор устанавливает значение
	float getNumber() const { return m_fnum; }; // получить значение
	char getOperator() const { return '0'; }; // просто некая функция

private:
	float m_fnum; // число
};

class Stack
{
public:
	Stack() { top = 0; };
	
	void push(Token *value) { token[++top] = value; }
	Token *pop() { return token[top--]; }
	int getTop() const { return top; }
	bool isNum()const
	{
		Number *ptr_number;
		if(ptr_number = dynamic_cast<Number*>(token[top]))
		{
			return 1;
		}
		else { return 0; }
	}

private:
	Token *token[100];

	int top;
};