#pragma once

#include "../stdafx.h"
#include <io.h>

namespace chapter11_10{

	constexpr int LENGTH = 80;
	constexpr int MAX_VALUE = 40;

	class Token
	{
	public:
		virtual float getNumber() const = 0;
		virtual char getOperator() const = 0;
	};

	class Operator : public Token
	{
	public:
		Operator(char oper) : m_oper(oper){}

		char  getOperator() const	{ return m_oper; }
		float getNumber()   const	{ return 0.0; }

	private:
		char m_oper; // + - / *
	};

	class Number : public Token
	{
	public:
		Number(float numb) :m_floatNum(numb){}

		char  getOperator() const { return '0'; }
		float getNumber()   const { return m_floatNum; }
	private:
		float m_floatNum;
	};

	class Stack
	{
	public:
		Stack() { m_top = 0; }

		void push(Token *value)
		{
			m_Token[++m_top] = value;
		}
		Token *pop() { return m_Token[m_top--]; }
		int gettop() const{ return m_top; }

		bool isNum() const
		{
			Number *ptr_Number;
			if (ptr_Number = dynamic_cast<Number *>(m_Token[m_top]))
				return 1;
			else return 0;
		}

	private:
		Token *m_Token[MAX_VALUE];
		int m_top;
	};

	class Express
	{
	public:
		Express(char *pointer)
		{
			m_ptrString = pointer;
			m_length = std::strlen(m_ptrString);
		}

		void parse();
		float solve();

	private:
		Stack m_Stack;
		char *m_ptrString;
		int m_length;
	};
}