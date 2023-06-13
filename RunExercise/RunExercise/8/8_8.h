#include "../stdafx.h"
#pragma once

const int LIMIT = 100;

class NewSafeArray
{
private:
	int mArray[LIMIT];
public:

	// function return reference
	int& operator [](int index);
};