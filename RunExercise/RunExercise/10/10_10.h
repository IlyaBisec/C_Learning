#pragma once
// Two classes that simulate working with variables andpointers.
// In this case, the computer's memory should be modeled using arrays.
// Then the array index will be analogous to the address in the computer's
// memory.
//
//
// Here the address in the computer's memory corresponds to the index of 
// the memory array.
// (The indexes of the fmemory array) are of the int type,
// so to simulate the part of the memory of the computer in which they 
// are stored, we will use the pmemory array of the int type.

#include "..\stdafx.h"

using namespace std;

// Part of the computer's memory that can only store 'float' type real numbers
const int fl_SIZE = 100;  // Count of places tp store numbers
float fl_Memory[fl_SIZE]; // Part of the computer's memory
int fl_Top = 0;			  // Next free place in this part of the computer's memory


// Part of the computer's memory that can only store addresses
// (addresses of any values in the computer's memory are also stored in memory)
const int pointer_SIZE = 100;	   // Count of places tp store addresses
int pointer_Memory[pointer_SIZE];  // Part of the computer's memory
int pointer_Top = 0;			   // Next free place in this part of the computer's memory


// Class, that models a variable of the float type
class Float
{
public:
	Float(float value)
	{
		fl_Memory[fl_Top] = value;
		m_Address = fl_Top;
		fl_Top++;
	}

	int operator&() const;

private:
	// The address in memory where the value of variable is stored
	int m_Address;
};


// Class, that models a pointer a variable of the float type
class PointerFloat
{
public:
	PointerFloat(int value)
	{
		pointer_Memory[pointer_Top] = value;
		m_pointerAddress = pointer_Top;
		pointer_Top++;
	}

	float &operator *()const;

private:
	// The address in memory where the pointer value is stored
	int m_pointerAddress;
};