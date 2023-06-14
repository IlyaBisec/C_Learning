#include "seven_nine.h"
#include "..\stdafx.h"

int main7_9()
{
	Matrix matrix(3, 4);
	int matrixValue = 12345;
	
	matrix.putel(7, 4, matrixValue);
	matrixValue = matrix.getel(7, 4);
	std::cout << matrixValue;

	return 0;
}

void Matrix::putel(int rows, int colunms, int arrayValue)
{
	if (rows < 0 || rows > LIMIT
		|| colunms < 0 || colunms > LIMIT)
	{
		std::cout << "Overflow array \n";
	}

	m_Array[rows][colunms] = arrayValue;
}

int Matrix::getel(int rows, int colunms)
{
	if (rows < 0 || rows > LIMIT
		|| colunms < 0 || colunms > LIMIT)
	{
		std::cout << "Overflow array \n";
	}

	return m_Array[rows][colunms];
}
