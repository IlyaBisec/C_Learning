#pragma once
#include "../stdafx.h"

class Token // Абстрактный базовый класс
{
public:
	virtual float getNumber() = 0; // чистая виртуальная
	// функция
	virtual char getOperator() = 0;
};
class Operator : public Token
{
public:
	Operator(char); // конструктор устанавливает значение
	char getOperator(); // получить значение
	float getNumber(); // просто некая функция

private:
	char m_oper; // Операторы +, -, *, /
};
class Number : public Token
{
public:
	Number(float); // конструктор устанавливает значение
	float getNumber(); // получить значение
	char getOperator(); // просто некая функция

private:
	float m_fnum; // число
};