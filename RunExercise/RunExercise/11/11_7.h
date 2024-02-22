#pragma once
#include "../stdafx.h"

class Token // ����������� ������� �����
{
public:
	virtual float getNumber() = 0; // ������ �����������
	// �������
	virtual char getOperator() = 0;
};
class Operator : public Token
{
public:
	Operator(char); // ����������� ������������� ��������
	char getOperator(); // �������� ��������
	float getNumber(); // ������ ����� �������

private:
	char m_oper; // ��������� +, -, *, /
};
class Number : public Token
{
public:
	Number(float); // ����������� ������������� ��������
	float getNumber(); // �������� ��������
	char getOperator(); // ������ ����� �������

private:
	float m_fnum; // �����
};