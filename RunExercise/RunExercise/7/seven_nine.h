#pragma once

const int LIMIT = 10;

class Matrix
{
public:
	int matrixRows, matrixColumns;

	Matrix(int rows, int colunms) : matrixRows(rows), 
		matrixColumns(colunms){}
	
	// putel gets the matrix rows and colunms,
	// and the array value
	void putel(int rows, int colunms, int arrayValue);
	// getel returns the matrix rows and colunms
	int getel(int rows, int colunms);

private:

	int m_Array[10][10];

};