#include "13_1.h"

void Verylong::put() const
{
	char copy[SIZE];
	strcpy_s(copy, m_string); // Create copy
	if (!m_sign && compare(Verylong(0L)) != 2) // If -digit & !=0
		std::cout << '-';
	std::cout << _strrev(copy); // Flip copy and display
}

void Verylong::get()
{	
	char tempStr[SIZE];
	std::cin >> tempStr;	// Get string from user

	// Check input sign
	// If the number is negative, the user will enter a minus sign '-' 
	// in front of it, if the number is positive, then the sign
	// is not required
	if(tempStr[0] == '-'){
		m_sign = false;
		strcpy_s(m_string, tempStr + 1);
	}
	else{
		m_sign = true;
		strcpy_s(m_string, tempStr);
	}

	m_length = strlen(m_string); // Find her length
	_strrev(m_string); // Flip
}

Verylong Verylong::operator+(const Verylong &largeNum)
{
	Verylong result;

	// If both terms are positive
	if(m_sign && largeNum.m_sign)
	{
		result = addBy(largeNum); // Sum their modules
		result.m_sign = true;  // Sum - positive
	}
	// If both terms are negative
	else if(!m_sign && !largeNum.m_sign)
	{
		result = addBy(largeNum); // Sum their modules
		result.m_sign = false; // Sum - negative
	}
	// If one of the terms is negative
	else
	{
		// If 1-st >
		if(compare(largeNum) == 1)
		{
			result = subtract(largeNum);  // Substrucrt 1st & 2st terms
			result.m_sign = m_sign; // Sign of result = sign greater term
		}
		// If 2-st >
		else if(compare(largeNum) == 0)
		{
			result = subtract(*this);  // Substrucrt 2st & 1st terms
			result.m_sign = largeNum.m_sign; // Sign of result = sign greater term
		}
		// If equal
		else
		{
			result = Verylong(0L);
		}
	}
	return result;
}

Verylong Verylong::operator-(const Verylong &largeNum)
{
	Verylong result;

	// If the reduced is positive and the subtracted is negative
	// a-(-b) = a+b
	if(m_sign && !largeNum.m_sign)
	{
		result = addBy(largeNum); // Sum their modules
		result.m_sign = true;  // Sum - positive
	}
	// If the reduced is negative and the subtracted is positive
	else if(!m_sign && largeNum.m_sign)
	{
		result = addBy(largeNum); // Sum their modules
		result.m_sign = false; // Sum - negative
	}
	// If the reduced and subtracted have the same sign
	else
	{
		// If reduced term >
		if(compare(largeNum) == 1)
		{
			result = subtract(largeNum);  // Substrucrt reduced & subtracted terms
			result.m_sign = m_sign; // Sign of result = sign reduced term
		}
		// If subtracted term >
		else if(compare(largeNum) == 0)
		{
			result = largeNum.subtract(*this);  // Substrucrt subtracted & reduced terms
			result.m_sign = !largeNum.m_sign; // Sign of result = the opposite sign
		}
		// If equal
		else
		{
			result = Verylong(0L);
		}
	}
	return result;
}

Verylong Verylong::operator*(const Verylong &largeNum)
{
	Verylong result;
	result = multiply(largeNum);

	// If the signs are equal
	if ((m_sign && largeNum.m_sign) || (!m_sign && !largeNum.m_sign))
		result.m_sign = true;
	else
		result.m_sign = false;

	return result;
}

Verylong Verylong::operator/(const Verylong &largeNum)
{
	Verylong result;
	result = divide(largeNum, true);

	// If the signs are equal
	if ((m_sign && largeNum.m_sign) || (!m_sign && !largeNum.m_sign))
		result.m_sign = true;
	else
		result.m_sign = false;

	return result;
}

Verylong Verylong::operator%(const Verylong &largeNum)
{
	Verylong result;

	// If 0
	if (compare(Verylong(0L)) == 2)
	{
		result = Verylong(0L); // The remainder of devision = 0
	}
	// If != 0
	else
	{
		// Find the remainder of division modules of divisible and divisor
		result = divide(largeNum, false);
		// Remainder sign = divisible sign
		result.m_sign = m_sign;
	}

	return result;
}

Verylong Verylong::addBy(const Verylong &largeNum) const
{
	char tempNumber[SIZE];
	int pos; // Position

	// Find the longest number
	int maxLen = (m_length > largeNum.m_length) ? m_length : largeNum.m_length;
	// Set in the 1, if sum of digit >= 10,
	int carry = 0;
	// start a cycle by bit addition
	for (pos = 0; pos < maxLen; pos++)
	{
		// Get the digit of the 1st term
		int term1 = (pos > m_length - 1) ? 0 : m_string[pos] - '0';
		// And more for the 2st term
		int term2 = (pos > largeNum.m_length - 1) ? 0 : largeNum.m_string[pos] - '0';

		// Sum digits & carry
		int digitSum = term1 + term2 + carry;
		// If the sum of digits >= 10, transfer
		if (digitSum >= 10)				
		   { digitSum -= 10; carry = 1; } // Decrease sum -10 and transfer 
		else
			// Else transfer = 0
			carry = 0;					
		
		tempNumber[pos] = digitSum + '0';
	}
	// If the transfer in the end
	// last digit = 1
	if (carry == 1)					
		tempNumber[pos++] = '1';
	tempNumber[pos] = '\0';

	// Delete leading zeros
	for(pos = strlen(tempNumber) - 1; pos > 0; pos--)
	{
		if (tempNumber[pos] == '0')
		{
			tempNumber[pos] = '\0';
		}
		else
		{
			break;
		}
	}

	return Verylong(tempNumber);
}

Verylong Verylong::subtract(const Verylong &largeNum) const
{
	char tempNumber[SIZE];
	int pos; // Position
	int carry = 0;

	// start a cycle by bit substraction
	for (pos = 0; pos < m_length; pos++)
	{
		// Get the substraction digit
		int digit1 = m_string[pos] - '0';
		// And get the substraction digit 2
		int digit2 = (pos > largeNum.m_length - 1) ? 0 : largeNum.m_string[pos] - '0';

		// Substraction digits & carry
		int digitSub = digit1 - digit2 - carry;
		// If the substraction of digits < 0, transfer
		if (digitSub < 0)				
		   { digitSub += 10; carry = 1; } // Increase substraction +10 and transfer 
		else
			// Else transfer = 0
			carry = 0;					
		
		tempNumber[pos] = digitSub + '0';
	}
	tempNumber[pos] = '\0';

	// Delete leading zeros
	for(pos = m_length - 1; pos > 0; pos--)
	{
		if (tempNumber[pos] == '0')
		{
			tempNumber[pos] = '\0';
		}
		else
		{
			break;
		}
	}

	return Verylong(tempNumber);
}

Verylong Verylong::multiply(const Verylong &largeNum) const
{
	Verylong singleProd; // A single-digit product
	Verylong currentSum;

	for(int i = 0; i < largeNum.m_length; i++)
	{
		// Get the multiplier digit
		int digit = largeNum.m_string[i] - '0';
		singleProd = multiDigit(digit); // Multiply the current one by it

		// Multiply the current result by 10 
		for (int j = 0; j < i; j++)
			singleProd = multi_10(singleProd); 

		currentSum = currentSum + singleProd;
	}
	return currentSum;
}

Verylong Verylong::divide(const Verylong &largeNum, bool flag) const
{
	if(largeNum.compare(Verylong(0L)) == 2) // If 0
	{
		std::cout << "\nThe divisor cannot be zero!\n";
		exit(1);
	}
	// If the divisor > the divisible 
	if(largeNum.compare(*this) == 1)
	{
		// Return the result: 0
		// Return the remainder of the division
		return (flag) ? Verylong(0L) : *this;
	}
	// If the divisor '<' or '=' the divisible
	char result[SIZE];
	Verylong dividend, divider;
	int pos = 0;

	dividend = *this;
	divider = largeNum;

	dividend.m_sign = true;
	divider.m_sign = true;

	do
	{	
		Verylong preDiv;

		// Multiply divisor by 10 while it gets as close to the divisible
		//  as possible
		while(divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			preDiv = divider;
			divider = multi_10(divider);
		}
		// Multiply divisor by the numbers 1 - 9 while it gets as close to the divisible as 
		// possible, while this number in the range 1 - 9 will become the next digit of 
		// the final answer
		int digit = 1;
		while(divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			digit++;
			divider = preDiv.multiDigit(digit);
		}
		digit--;
		divider = preDiv.multiDigit(digit);

		// Write founded in the result
		result[pos++] = digit + '0';

		// Substract from dividend
		dividend = dividend - divider;

		divider = largeNum;
	}
	// While the divisor '<' or '=' the divisible
	while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2);

	result[pos] = '\0';
	_strrev(result);

	return (flag) ? Verylong(result) : dividend;
}

Verylong Verylong::multiDigit(const int digit2) const
{
	char tempNum[SIZE];
	int pos, carry = 0;

	// start a cycle by digits of the current number
	for (pos = 0, pos < m_length; pos++;)
	{
		int digit1 = m_string[pos] - '0';
		int digitProd = digit1 * digit2;
		digitProd += carry;

		// If result >= 10, transfer
		if (digitProd >= 10)
		{
			// transfer = digit from higher number
			carry = digitProd / 10;
			// Current result = digit from lower number
			digitProd -= carry * 10;
		} 
		else
		{
			// Transfer = 0
			carry = 0;
		}
		tempNum[pos] = digitProd + '0';
	}
	// If there is a transfer from the last multiplication
	// Add more higher number with transfer
	if (carry != 0)
		tempNum[pos++] = carry + '0';
	tempNum[pos] = '\0';

	return Verylong(tempNum);
	
}

Verylong Verylong::multi_10(const Verylong &largeNum) const
{
	char tempNumber[SIZE];
	for(int i = largeNum.m_length - 1; i >= 0; i--) 
	{
		tempNumber[i + 1] = largeNum.m_string[i]; // Move one digit higher
	}
	tempNumber[0] = '0'; // Reset the lowest digit
	tempNumber[largeNum.m_length + 1] = '\0';

	return Verylong(tempNumber);
}

int Verylong::compare(const Verylong &largeNumber) const
{
	if (m_length > largeNumber.m_length)	// Count of ranks current digit > argument
		return 1;
	else if (m_length < largeNumber.m_length) // Count of ranks current digit < argument
		return 0;
	// Count of ranks current digit = argument,
	// let's compare the numbers bit by bit starting from the highest digit
	else	
		for(int i = m_length - 1; i >= 0; i--)
		{
			if (m_string[i] - '0' > largeNumber.m_string[i] - '0')
				return 1;
			else if (m_string[i] - '0' < largeNumber.m_string[i] - '0')
				return 0;
		}

	return 2;
}
