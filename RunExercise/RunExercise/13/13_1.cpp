#include "13_1.h"

void Verylong::put() const
{
	char copy[SIZE];
	strcpy(copy, m_vl_string); // Create copy
	std::cout << strrev(copy); // Flip copy and display
}

void Verylong::get()
{
	std::cin >> m_vl_string;	// Get string from user
	m_vl_len = strlen(m_vl_string); // Find her length
	strrev(m_vl_string); // Flip
}

Verylong Verylong::operator+(const Verylong &largeNum)
{
	char tempNumber[SIZE];
	int pos; // Position

	// Find the longest number
	int maxLen = (m_vl_len > largeNum.m_vl_len) ? m_vl_len : largeNum.m_vl_len;
	// Set in the 1, if sum >= 10
	int carry = 0;
	for (pos = 0; pos < maxLen; pos++)
	{
		// Get discharge(rank)
		int rank1 = (pos > m_vl_len - 1) ? 0 : m_vl_string[pos] - '0';
		// And more
		int rank2 = (pos > largeNum.m_vl_len - 1) ? 0 : largeNum.m_vl_string[pos] - '0';

		// Sum ranks
		int rankSum = rank1 + rank2 + carry;
		// If the transfer
		// rankSum += 10
		// Set the transfer 1
		if (rankSum >= 10)				
		   { rankSum -= 10; carry = 1; } 
		else
			// Else the transfer = 0
			carry = 0;					
		
		tempNumber[pos] = rankSum + '0';
	}
	// If the transfer in the end
	// last digit = 1
	if (carry == 1)					
		tempNumber[pos++] = '1';
	tempNumber[pos] = '\0';

	return Verylong(tempNumber);
	
}

Verylong Verylong::operator*(const Verylong &largeNum)
{
	Verylong singleProd; // A single-digit product
	Verylong currentSum;

	for(int i = 0; i < largeNum.m_vl_len; i++)
	{
		// Get discharge(rank)
		int rank = largeNum.m_vl_string[i] - '0';
		singleProd = multDigit(rank); // Multiply the current one by it

		// Multi the current result by a power of 10 
		for (int j = 0; j < i; j++)
			singleProd = mult_10(singleProd); 

		currentSum = currentSum + singleProd;
	}
	return currentSum;
}

Verylong Verylong::multDigit(const int rank2) const
{
	char tempNum[SIZE];
	int pos, carry = 0;

	for (pos = 0, pos < m_vl_len; pos++)
	{
		int rank1 = m_vl_string[pos] - '0';
		int rankProd = rank1 * rank2;
		rankProd += carry;

		if (rankProd >= 10)
		{
			carry = rankProd / 10;
			rankProd -= carry * 10;
		} 
		else
		{
			carry = 0;
		}
		tempNum[pos] = rankProd + '0';
	}
	if (carry != 0)
		tempNum[pos++] = carry + '0';
	tempNum[pos] = '\0';

	return Verylong(tempNum);
	
}

Verylong Verylong::mult_10(const Verylong &largeNum) const
{
	char tempNumber[SIZE];
	for(int i = largeNum.m_vl_len - 1; i >= 0; i--) // Move one rank higher
	{
		tempNumber[i + 1] = largeNum.m_vl_string[i];
	}
	tempNumber[0] = '0'; // Reset the lowest rank
	tempNumber[largeNum.m_vl_len + 1] = '\0';

	return Verylong(tempNumber);
}
