#pragma once
#include "..\stdafx.h"


class Employee
{
public:

	void getData();
	void putData();

private:

	std::string m_NameOfWorker;
	long m_NumberOfWorker;
};