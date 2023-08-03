#pragma once

// 100 integers are stored so as to have easy access to them.
// 10 different arrays of 10 elements each and an array of
// 10 pointers to these arrays. Arrays will have names a1, a2, a3, etc.
// The address of each array will be stored in an array of pointers of type 
// int*, which is called 'ptr_Ap'. Getting access to a single integer
// using the expression ap[j][k], where 'j' is the number of the array element
// pointers, and 'k' is the number of the element in the array that this pointer
// points to.

#include "..\stdafx.h"

using namespace std;

const int SIZE = 10; // Number of elements in the array

void tenArrays();