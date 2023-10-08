// A reliable array that checks the
// ouput of indexes outside the array

#pragma once

const int LIMIT = 80;

class SafeArray
{

public:
	// Putel gets the array index and the index value
	void putel(int index, int indexValue);
	// Getel gets the array index and returns the index value
	int getel(int index) const;
	// Checking the array against overflow
	void checkOverflow(int index)const;

private:
	int m_array[LIMIT];
};