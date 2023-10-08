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
    
    static const int m_size = 5;
    float m_array[m_size];

    float *m_ptrFloat;

    char m_choice;
    int m_number = 0;
    float m_total = 0.0; 
    float m_average;

};