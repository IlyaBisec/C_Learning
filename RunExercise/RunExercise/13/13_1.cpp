#include "13_1.h"


// Displaying a very long integer on the screen
void Verylong::put() const
{
	wchar_t temp[SIZE];
	// Copy the number to a string
	wcscpy(temp, m_string);                 
	// If number is negative and != 0
	if (!m_sign && compare(Verylong(0L)) != 2)
		wcout << L'-';                   // Put a minus sign in front of it
	wcout << _wcsrev(temp);              // Flip him and dipslay it
}

// Getting a number from the user
void Verylong::get()
{
	wchar_t user_input[SIZE];

	wcin >> user_input;


	// If !number and !-number
	for (int i = 0; user_input[i] != L'\0'; ++i)
	{
		if (!iswdigit(user_input[i]) && !(i == 0 && user_input[i] == L'-'))
		{
			wcerr << L"Unccorrect input, pls number only." << endl;
			exit(1);
		}
	}

	// If the user has entered a minus sign '-' for a negative number
	if (user_input[0] == L'-')  // Get sign
	{
		m_sign = false; wcscpy(m_string, user_input + 1);
	}
	// Otherwise, the number is positive and the plus sign is not required, respectively,
	// the user enters only numbers
	else
	{
		m_sign = true; wcscpy(m_string, user_input);
	}

	m_length = wcslen(m_string); // Find number length
	_wcsrev(m_string);       // Flip him

}

// Find the sum of very long integers
Verylong Verylong::operator+ (const Verylong v)
{
	Verylong res;

	// If both terms are positive
	if (m_sign && v.m_sign)  
	{
		res = addBy(v); // Add their modules
		res.m_sign = true; // Sum - positive
	}
	// If both terms are negative
	else if (!m_sign && !v.m_sign) 
	{
		res = addBy(v); // Add their modules
		res.m_sign = false; // Sum — negative
	}
	// If one of the terms is negative
	else                          
	{
		// If 1'st > 2'st
		if (compare(v) == 1)  
		{
			res = subtract(v); // Consider the difference between the first and second terms
			res.m_sign = m_sign;  // Result sign — the sign of the larger term
		}
		// If 2'st > 1'st
		else if (compare(v) == 0) 
		{
			res = v.subtract(*this); // Consider the difference between the second and first terms
			res.m_sign = v.m_sign;   // Result sign — the sign of the larger term
		}
		//  If 1'st == 2'st
		else                         
			res = Verylong(0L);  // Result = 0   
	}

	return res;
}

// Find the difference of very long integers
Verylong Verylong::operator- (const Verylong v)
{
	Verylong res;

	// If the reduced is positive and the subtracted is negative
	// a - (-b) = a + b
	if (m_sign && !v.m_sign)
	{                              
		res = addBy(v); 
		res.m_sign = true;          
	}
	//  –a – b = –(a + b)
	else if (!m_sign && v.m_sign)     
	{                              
		res = addBy(v); 
		res.m_sign = false;       
	}
	// If the reduced and subtracted have the same sign
	else            
	{
		// If the reduced value is greater
		if (compare(v) == 1)                
		{
			res = subtract(v);      
			res.m_sign = m_sign;                  
												
		}
		// If the deductible is greater,
		else if (compare(v) == 0)             
		{
			res = v.subtract(*this); 
			res.m_sign = !v.m_sign;                 
												
		}
		// If equal
		else                              
			res = Verylong(0L);                
	}

	return res;
}

// The algorithm for adding very large numbers
Verylong Verylong::addBy(const Verylong v) const
{
	wchar_t temp[SIZE];
	int j;
	// Get legth
	int maxlen = (m_length > v.m_length) ? m_length : v.m_length;
	int carry = 0;                         // Transfer = 1,
										   // If sum of bits >= 10
	for (j = 0; j < maxlen; j++)           
	{
		int d1 = (j > m_length - 1) ? 0 : m_string[j] - L'0';     
		int d2 = (j > v.m_length - 1) ? 0 : v.m_string[j] - L'0';
		int digitsum = d1 + d2 + carry;    
		if (digitsum >= 10)                // If sum of bits >= 10, trasfer
		{
			digitsum -= 10; carry = 1;
		} // Decrease sum on 10 and set transfer
		else
			carry = 0;                     
		temp[j] = digitsum + L'0';         
	}
	if (carry == 1)                        
		temp[j++] = L'1';                 
	temp[j] = L'\0';                      

	// Insert the removal of the leading zeros
	for (j = wcslen(temp) - 1; j > 0; j--)
	{
		if (temp[j] == L'0')               
			temp[j] = L'\0';              
										  
		else
			break;                      
	}

	return Verylong(temp);                
}

// The algorithm for sunbtration very large numbers
Verylong Verylong::subtract(const Verylong v) const
{
	wchar_t temp[SIZE];
	int j;
	int carry = 0;                         

	for (j = 0; j < m_length; j++)            
	{
		int d1 = m_string[j] - L'0';                         
		int d2 = (j > v.m_length - 1) ? 0 : v.m_string[j] - L'0'; 
		int digitres = d1 - d2 - carry;  
		
		// Calculate the difference between these numbers, taking into account the transfer
		
		// If the difference is < 0, then carry out the transfer
		if (digitres < 0)                 
		{
			digitres += 10; carry = 1;
		} // Increase the difference by 10 and set the transfer
		else
			carry = 0;                    
		temp[j] = digitres + L'0';         
	}
	temp[j] = L'\0';                       

	
	for (j = m_length - 1; j > 0; j--)
	{
		if (temp[j] == L'0')               // If the digit contains 0,
			temp[j] = L'\0';               // Reduce our number by this category
										   // and move on to checking the next discharge
		else
			break;                         // Otherwise, exit the loop
	}

	return Verylong(temp);              
}

// If the current number is greater than the argument, then 1 is returned, if less than 0,
// if equal, 2 is returned
int Verylong::compare(const Verylong v) const
{
	if (m_length > v.m_length)      // The number of digits of the current number is greater than that of the argument
		return 1;
	else if (m_length < v.m_length) // The number of digits of the current number is lower than that of the argument
		return 0;
	else                                    // Equal
		for (int j = m_length - 1; j >= 0; j--) 
		{                                   
			if (m_string[j] - L'0' > v.m_string[j] - L'0')
				return 1;
			else if (m_string[j] - L'0' < v.m_string[j] - L'0')
				return 0;
			
		}
	return 2;
}

// Find the multiplication of very long integers
Verylong Verylong::operator* (const Verylong v)
{
	Verylong res;

	res = multiply(v);           
	if ((m_sign && v.m_sign) || (!m_sign && !v.m_sign)) 
		res.m_sign = true;                       
	else                                       
		res.m_sign = false;                      

	return res;
}

// The algorithm for multuply very large numbers
Verylong Verylong::multiply(const Verylong v) const
{
	Verylong pprod;                       
	Verylong tempsum;                     
	for (int j = 0; j < v.m_length; j++)       
	{
		int digit = v.m_string[j] - L'0';     
		pprod = multdigit(digit);          
		for (int k = 0; k < j; k++)        
			pprod = mult10(pprod);         
		tempsum = tempsum + pprod;        
	}
	return tempsum;                      
}

// Find the result of integer division of very long integers
Verylong Verylong::operator/ (const Verylong v)
{
	Verylong res;

	res = devide(v, true);         
												
	if ((m_sign && v.m_sign) || (!m_sign && !v.m_sign)) 
		res.m_sign = true;                        
	else                                       
		res.m_sign = false;                       

	return res;
}

// Find the remainder of the integer division of very long integers
Verylong Verylong::operator% (const Verylong v)
{
	Verylong res;

	if (compare(Verylong(0L)) == 2)           
		res = Verylong(0L);               
	else
	{                                    
		res = devide(v, false); 
										  
		res.m_sign = m_sign;                
	}

	return res;
}

// The natural integer division algorithm returns the result of integer division, or the remainder,
// depending on the value of the flag argument: true is the result, false is the remainder
Verylong Verylong::devide(const Verylong v, bool flag) const
{
	if (v.compare(Verylong(0L)) == 2)          // If the divisor is 0
	{
		wcout << L"\nThe divisor cannot be zero!" << endl;
		exit(1);                        
	}

	if (v.compare(*this) == 1)                    // If the divisor is greater than the divisible
		return (flag) ? Verylong(0L) : *this; 
								
	wchar_t res[SIZE];
	Verylong dividend, divider;
	int j = 0;

	dividend = *this;
	divider = v;

	dividend.m_sign = true;
	divider.m_sign = true;

	// As long as the divisor is less than or equal to the divisible one
	do {                            

		// Multiply the divisor by 10 until it gets as close to the divisible as possible
		Verylong prevdiv;
		while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			prevdiv = divider;
			divider = mult10(divider);
		}
		divider = prevdiv;

		// Multiply the divisor by the numbers from 1 to 9 until it gets as close to the divisible as possible,
		// at the same time, this number in the range from 1 to 9 will become the next digit of the final answer
		int digit = 1;
		while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			digit++;
			divider = prevdiv.multdigit(digit);
		}
		digit--;
		divider = prevdiv.multdigit(digit);

		res[j++] = digit + L'0';

		dividend = dividend - divider;

		divider = v;

	} while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2);

	res[j] = L'\0';                          
	_wcsrev(res);                             
	return (flag) ? Verylong(res) : dividend;
}

// Multiplying the argument by 10
Verylong Verylong::mult10(const Verylong v) const
{
	wchar_t temp[SIZE];
	for (int j = v.m_length - 1; j >= 0; j--)  
		temp[j + 1] = v.m_string[j];          
	temp[0] = L'0';                        
	temp[v.m_length + 1] = L'\0';              
	return Verylong(temp);                
}

// Multiplying the current number by a digit argument
Verylong Verylong::multdigit(const int d2) const
{
	wchar_t temp[SIZE];
	int j, carry = 0;
	for (j = 0; j < m_length; j++)            
	{
		int d1 = m_string[j] - L'0';          
		int digitprod = d1 * d2;           
		digitprod += carry;               
		if (digitprod >= 10)              
		{
			carry = digitprod / 10;        
			digitprod -= carry * 10;       
		}
		else
			carry = 0;                     
		temp[j] = digitprod + L'0';       
	}
	if (carry != 0)                       
		temp[j++] = carry + L'0';          
	temp[j] = L'\0';                       
	return Verylong(temp);                 
}

