#pragma once

const int LIMIT = 80;

class SafeArray
{
private:
	
	int mArray[LIMIT];
public:
	
	// putel gets the array index and the index value
	void putel(int index, int indexValue);
	// getel gets the array index and returns the index value
	int getel(int index);
};