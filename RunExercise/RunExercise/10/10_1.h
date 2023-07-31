// Using 'pointers' to calculate the arithmetic mean 
// and display it on the screen 

#pragma once
 
#include <iostream>

using namespace std;

class Pointers
{
public:

    void calculateArithmeticMean();

private:
    
    static const int m_Size = 5;
    float m_Array[m_Size];

    float *m_ptrFloat;

    char m_Choice;
    int m_Number = 0;
    float m_Total = 0.0; 
    float m_Average;

};