// A reliable array that checks the
// ouput of indexes outside the array

#pragma once

const int LIMIT = 80;

class SafeArray
{

public:
	// putel gets the array index and the index value
	void putel(int index, int indexValue);
	// getel gets the array index and returns the index value
	int getel(int index);

private:
	int m_Array[LIMIT];
};