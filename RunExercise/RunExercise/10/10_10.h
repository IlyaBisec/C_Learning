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
constexpr int g_SIZE = 100;  // Count of places tp store numbers & Count of places tp store addresses
float g_memory[g_SIZE];      // Part of the computer's memory
int g_top = 0;			     // Next free place in this part of the computer's memory


// Part of the computer's memory that can only store addresses
// (addresses of any values in the computer's memory are also stored in memory)
int g_pMemory[g_SIZE];		// Part of the computer's memory
int g_pTop = 0;			    // Next free place in this part of the computer's memory


// Class, that models a variable of the float type
class Float
{
public:
	Float(float value)
	{
		g_memory[g_top] = value;
		m_address = g_top;
		g_top++;
	}

	int operator&() const;

private:
	// The address in memory where the value of variable is stored
	int m_address;
};


// Class, that models a pointer a variable of the float type
class PointerFloat
{
public:
	PointerFloat(int value)
	{
		g_pMemory[g_pTop] = value;
		m_pointerAddress = g_pTop;
		g_pTop++;
	}

	float &operator *()const;

private:
	// The address in memory where the pointer value is stored
	int m_pointerAddress;
};