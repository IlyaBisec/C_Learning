// Demonstration of the operation
// of a two-dimensional array - Matrix

#pragma once

const int LIMIT = 10;

class Matrix
{
public:
	int matrixRows, matrixColumns;

	Matrix(int rows, int colunms) : matrixRows(rows), 
		matrixColumns(colunms){}
	
	// Putel gets the matrix rows and colunms,
	// and the array value
	void putel(int rows, int colunms, int arrayValue);
	// Getel returns the matrix rows and colunms
	int getel(int rows, int colunms);

private:

	int m_Array[10][10];

};