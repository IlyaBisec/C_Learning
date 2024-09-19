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
	wchar_t temp[SIZE];
	wcin >> temp;  

	// If the user has entered a minus sign '-' for a negative number
	if (temp[0] == L'-')  // Get sign
	{
		m_sign = false; wcscpy(m_string, temp + 1);
	}
	// Otherwise, the number is positive and the plus sign is not required, respectively,
	// the user enters only numbers
	else
	{
		m_sign = true; wcscpy(m_string, temp);
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
		res.m_sign = false; // Sum � negative
	}
	// If one of the terms is negative
	else                          
	{
		// If 1'st > 2'st
		if (compare(v) == 1)  
		{
			res = subtract(v); // Consider the difference between the first and second terms
			res.m_sign = m_sign;  // Result sign � the sign of the larger term
		}
		// If 2'st > 1'st
		else if (compare(v) == 0) 
		{
			res = v.subtract(*this); // Consider the difference between the second and first terms
			res.m_sign = v.m_sign;   // Result sign � the sign of the larger term
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
	{                              //     �� ���� ���������� ��������: a � (�b) = a + b
		res = addBy(v); // ���������� �� ������
		res.m_sign = true;           // ���� � �����������
	}
	else if (!m_sign && v.m_sign)      // ���� ����������� ������������, � ���������� ������������
	{                              //     �� ���� ����������: �a � b = �(a + b)
		res = addBy(v); // ���������� �� ������
		res.m_sign = false;          // ���� � �����������
	}
	else                           // ���� ����������� � ���������� ����� ���� � ��� �� ����
	{
		if (compare(v) == 1)                  // ���� ����������� ������,
		{
			res = subtract(v);       // ������� ������� ������������ � �����������
			res.m_sign = m_sign;                    // ���� ���������� � ���� ������������
												// (��� ���� �����������, ��� �� ��� �����)
		}
		else if (compare(v) == 0)             // ���� ���������� ������,
		{
			res = v.subtract(*this); // ������� ������� ����������� � ������������
			res.m_sign = !v.m_sign;                 // ���� ���������� � ����, ���������������
												// ����� ������������ (��� �����������, ��� �����)
		}
		else                              // ����������� � ���������� �����
			res = Verylong(0L);                 // ��������� ����� 0
	}

	return res;
}

// ����������� ��������: ������� ����� ���� ������������� ����� ������� ����� �����,
// �� ���� ���� �������� ���� ����� ������������� ����� ������� ����� ������
// (����� ���� ����������� ����� ���� ����������� �����)
Verylong Verylong::addBy(const Verylong v) const
{
	wchar_t temp[SIZE];
	int j;
	// ������� ����� ����� �������� ����������
	int maxlen = (m_length > v.m_length) ? m_length : v.m_length;
	int carry = 0;                         // ������� ������ ����� 1,
										   // ���� ����� �������� ����� >= 10
	for (j = 0; j < maxlen; j++)           // ������ ���� ������������ ��������
	{
		int d1 = (j > m_length - 1) ? 0 : m_string[j] - L'0';     // ������� ����� 1-�� ����������
		int d2 = (j > v.m_length - 1) ? 0 : v.m_string[j] - L'0'; // ������� ����� 2-�� ����������
		int digitsum = d1 + d2 + carry;    // ��������� ����� � �������
		if (digitsum >= 10)                // ���� ����� ���� >= 10, �� ��������� �������
		{
			digitsum -= 10; carry = 1;
		} // �������� ����� �� 10 � ��������� �������
		else
			carry = 0;                     // ����� �������� ���, �� ����� ����
		temp[j] = digitsum + L'0';         // ����������� ����� � ������ � �������� � ����
	}
	if (carry == 1)                        // ���� ������� ������� �� ���������� ��������,
		temp[j++] = L'1';                  // ��������� ��� ���� ������� ������, ������ 1
	temp[j] = L'\0';                       // ��������� ����� ������ ������� ��������

	// ������� �������� ������� ����� �� ������ ������
	for (j = wcslen(temp) - 1; j > 0; j--)
	{
		if (temp[j] == L'0')               // ���� ������ �������� 0,
			temp[j] = L'\0';               // ��������� ���� ����� �� ���� ������
										   // � ������� � �������� ���������� �������
		else
			break;                         // ����� ����� �� �����
	}

	return Verylong(temp);                 // ��������� ��������� ��������
}

// ����������� ���������: ������� ������� ���� ������������� ����� ������� ����� �����,
// ��� ���� ������ ����������� �������: ������ �� ���� ����� ������ ������� ��� ����� ���,
// �� ���� ���� ��������� ���� ����� ������������� ����� ������� ����� ������
// (������� ���� ����������� ����� ���� ����������� �����, ���� ����������� ������
// ����������� ��� ����� ���)
Verylong Verylong::subtract(const Verylong v) const
{
	wchar_t temp[SIZE];
	int j;
	int carry = 0;                         // ������� �� �������� �������

	for (j = 0; j < m_length; j++)             // ������ ���� ������������ ���������
	{
		int d1 = m_string[j] - L'0';                          // ������� ����� ������������
		int d2 = (j > v.m_length - 1) ? 0 : v.m_string[j] - L'0'; // ������� ����� �����������
		int digitres = d1 - d2 - carry;    // ��������� �������� ���� ����
										   // � ������ ��������
		if (digitres < 0)                  // ���� �������� < 0, �� ��������� �������
		{
			digitres += 10; carry = 1;
		} // �������� �������� �� 10 � ��������� �������
		else
			carry = 0;                     // ����� �������� ���, �� ����� ����
		temp[j] = digitres + L'0';         // ����������� ����� � ������ � �������� � ����
	}
	temp[j] = L'\0';                       // ��������� ����� ������ ������� ��������

	// ��� � temp ��� ���������� ��������� ���������, �� � ���� ���������� �����
	// ���� ������� ����; ��������, ��� ���������� ������� 1000 � 999 � temp
	// ����� �������� ����� 1 � ���� ������ "1000" (������, ��� ����� �� ������ �
	// "������������" ����), �� ���� � ����� �������� ������; ������� �����
	// ������� �������� ���� ������� �����, ���� ��� ���� � ����������

	// ����� �������� �� �������� � �������� �������,
	// ������� ������ (j == 0) ��������� �� �����, ��� ��� � ����� ������ ��������
	// ���� �� ���� ������
	for (j = m_length - 1; j > 0; j--)
	{
		if (temp[j] == L'0')               // ���� ������ �������� 0,
			temp[j] = L'\0';               // ��������� ���� ����� �� ���� ������
										   // � ������� � �������� ���������� �������
		else
			break;                         // ����� ����� �� �����
	}

	return Verylong(temp);                 // ��������� ��������� ���������
}

// ���� ������� ����� ������ ���������, �� ������������ 1, ���� ������ � 0,
// ��� ��������� ������������ 2 (������������ ������ �����, ��� ����� ������)
int Verylong::compare(const Verylong v) const
{
	if (m_length > v.m_length)      // ���-�� �������� �������� ����� ������, ��� � ���������
		return 1;
	else if (m_length < v.m_length) // ���-�� �������� �������� ����� ������, ��� � ���������
		return 0;
	else                                    // ��� ������ ���-�� ��������
		for (int j = m_length - 1; j >= 0; j--) // ������� ����� ����������,
		{                                   // ������� �� �������� �������
			if (m_string[j] - L'0' > v.m_string[j] - L'0')
				return 1;
			else if (m_string[j] - L'0' < v.m_string[j] - L'0')
				return 0;
			// ���� ������� �����, ��������� � ��������� ����� ������� ��������
		}
	// ���� ����� �����, ��
	return 2;
}

// ����� ������������ ����� ������� ����� �����
Verylong Verylong::operator* (const Verylong v)
{
	Verylong res;

	res = multiply(v);            // ������� ������������ ������� ������������
	if ((m_sign && v.m_sign) || (!m_sign && !v.m_sign)) // ���� ����������� ����� ���������� �����,
		res.m_sign = true;                        // ���� � �����������
	else                                        // ���� ����������� ����� ������ �����,
		res.m_sign = false;                       // ���� � �����������

	return res;
}

// ����������� ��������� ����� ������� ����� �����
Verylong Verylong::multiply(const Verylong v) const
{
	Verylong pprod;                        // ������������ ���� �� ������ �������
	Verylong tempsum;                      // ������� ����� ������������
	for (int j = 0; j < v.m_length; j++)       // ��������� ����� �� �������� ���������
	{
		int digit = v.m_string[j] - L'0';     // ������� ����� ���������
		pprod = multdigit(digit);          // ������� �������� �� ��� �����
		for (int k = 0; k < j; k++)        // ������� ��������� �� 10
			pprod = mult10(pprod);         // ������ ���������� (k) ���
		tempsum = tempsum + pprod;         // �������� ��������� ������������ � �������� �����
	}
	return tempsum;                        // ��������� ��������� ���������
}

// ����� ��������� �������������� ������� ����� ������� ����� �����
Verylong Verylong::operator/ (const Verylong v)
{
	Verylong res;

	res = devide(v, true);            // ������� ��������� ������� �������
												// �������� � ��������
	if ((m_sign && v.m_sign) || (!m_sign && !v.m_sign)) // ���� ������� � �������� ����� ���������� �����,
		res.m_sign = true;                        // ���� � �����������
	else                                        // ���� ������� � �������� ����� ������ �����,
		res.m_sign = false;                       // ���� � �����������

	return res;
}

// ����� ������� �� �������������� ������� ����� ������� ����� �����
Verylong Verylong::operator% (const Verylong v)
{
	Verylong res;

	if (compare(Verylong(0L)) == 2)           // ���� ������� ����� 0
		res = Verylong(0L);               // ������� �� ������� ����� 0
	else
	{                                     // ���� ������� �� ����� 0
		res = devide(v, false); // ������� ������� �� ������� �������
										  // �������� � ��������
		res.m_sign = m_sign;                  // ���� ������� ����� ����� ��������
	}

	return res;
}

// ����������� ������������� �������: ���������� ��������� �������������� �������, ���� �������,
// � ����������� �� �������� ��������� flag: true � ���������, false � �������
// (����� ������������ ����� ��������, ��� ������� � �������� � ������������� �����)
Verylong Verylong::devide(const Verylong v, bool flag) const
{
	if (v.compare(Verylong(0L)) == 2)          // ���� �������� ����� 0
	{
		wcout << L"\n������! �������� �� ����� ���� ����� ����!" << endl;
		exit(1);                           // ��������� ���������
	}

	if (v.compare(*this) == 1)                    // ���� �������� ������ ��������
		return (flag) ? Verylong(0L) : *this; // ��������� ������ ������ �
											  // ���������� ��������� �������: 0
											  // ������� �� �������: �������

										   // ���� �������� ������ �������� ��� ����� ���
	wchar_t res[SIZE];
	Verylong dividend, divider;
	int j = 0;

	dividend = *this;
	divider = v;

	dividend.m_sign = true; // ��� ��� ��� ����������� �������, ���������� ���
	divider.m_sign = true;  // ��� ����� ������ �������� � ��������

	do {                                   // ����, ���� �������� ������ �������� ��� ����� ���

		// �������� �������� �� 10, ���� �� �� ����������� � �������� ��� ����� �����
		Verylong prevdiv;
		while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			prevdiv = divider;
			divider = mult10(divider);
		}
		divider = prevdiv;

		// �������� �������� �� ����� �� 1 �� 9, ���� �� �� ����������� � �������� ��� ����� �����,
		// ��� ���� ��� ����� � �������� �� 1 �� 9 ������ ��������� ������ ��������� ������
		int digit = 1;
		while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			digit++;
			divider = prevdiv.multdigit(digit);
		}
		digit--;
		divider = prevdiv.multdigit(digit);

		// ������� ��������� ����� ������ � ����
		res[j++] = digit + L'0';

		// ������� �� �������� ������������ �����
		dividend = dividend - divider;

		// ������ �������� � ��������������� ��������
		divider = v;

	} while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2);

	res[j] = L'\0';                           // ����� ������
	_wcsrev(res);                             // ���������� ����
	return (flag) ? Verylong(res) : dividend; // ��������� ��������� ��� �������
}

// ��������� ��������� �� 10
Verylong Verylong::mult10(const Verylong v) const
{
	wchar_t temp[SIZE];
	for (int j = v.m_length - 1; j >= 0; j--)  // ������� ����� � �������-������
		temp[j + 1] = v.m_string[j];          // �� ���� ������� ������
	temp[0] = L'0';                        // �������� ���� � �������������� ������� �����
	temp[v.m_length + 1] = L'\0';              // ��������� ����� ������
	return Verylong(temp);                 // ��������� ���������
}

// ��������� �������� ����� �� ��������-�����
Verylong Verylong::multdigit(const int d2) const
{
	wchar_t temp[SIZE];
	int j, carry = 0;
	for (j = 0; j < m_length; j++)             // ��������� ����� �������� �����
	{
		int d1 = m_string[j] - L'0';          // ������� ����� �������� �����
		int digitprod = d1 * d2;           // ������� �� �� ��������-�����
		digitprod += carry;                // �������� � ������������ �������
		if (digitprod >= 10)               // ���� ��������� >= 10, ���������� �������
		{
			carry = digitprod / 10;        // ������� ����� ����� �� �������� �������
			digitprod -= carry * 10;       // ������� ��������� � ����� �� �������� �������
		}
		else
			carry = 0;                     // ����� ������� ����� ���� (�������� ���)
		temp[j] = digitprod + L'0';        // ����������� ����� � ������ � �������� � ����
	}
	if (carry != 0)                        // ���� ������� ������� �� ���������� ������������,
		temp[j++] = carry + L'0';          // ��������� ��� ���� ������� ������ � ���������
	temp[j] = L'\0';                       // ��������� ����� ������
	return Verylong(temp);                 // ��������� ���������
}

