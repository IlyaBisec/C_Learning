// Checking the overflow of the
// array from above and below

#include "../stdafx.h"
#pragma once

const int LIMIT = 100;

class NewSafeArray
{
public:

	// Function return reference
	int& operator [](int index);

private:
	int m_array[LIMIT];
};