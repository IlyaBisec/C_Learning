#include "10_10.h"

int main10_10()
{
	Float fVariable1 = 2.414;
	Float fVariable2 = 12.144;

	PointerFloat pf_Var1 = &fVariable1;
	PointerFloat pf_Var2 = &fVariable2;

	cout << "*pf_Var1: " << *pf_Var1<<"\n";
	cout << "*pf_Var2: " << *pf_Var2<<"\n\n";

	*pf_Var1 = 31.31;
	*pf_Var2 = 41.41;

	cout << "*pf_Var1: " << *pf_Var1 << "\n";
	cout << "*pf_Var2: " << *pf_Var2 << "\n\n";

	return 0;
}

int Float::operator&() const
{
	return m_address;
}

float &PointerFloat::operator*() const
{
	return fl_Memory[pointer_Memory[m_pointerAddress]];
}
