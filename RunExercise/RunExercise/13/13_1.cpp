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
	{                              //     то есть получается сложение: a – (–b) = a + b
		res = addBy(v); // складываем их модули
		res.m_sign = true;           // итог — положителен
	}
	else if (!m_sign && v.m_sign)      // если уменьшаемое отрицательно, а вычитаемое положительно
	{                              //     то есть получается: –a – b = –(a + b)
		res = addBy(v); // складываем их модули
		res.m_sign = false;          // итог — отрицателен
	}
	else                           // если уменьшаемое и вычитаемое имеют один и тот же знак
	{
		if (compare(v) == 1)                  // если уменьшаемое больше,
		{
			res = subtract(v);       // считаем разницу уменьшаемого и вычитаемого
			res.m_sign = m_sign;                    // знак результата — знак уменьшаемого
												// (или знак вычитаемого, они же тут равны)
		}
		else if (compare(v) == 0)             // если вычитаемое больше,
		{
			res = v.subtract(*this); // считаем разницу вычитаемого и уменьшаемого
			res.m_sign = !v.m_sign;                 // знак результата — знак, противоположный
												// знаку уменьшаемого (или вычитаемого, они равны)
		}
		else                              // уменьшаемое и вычитаемое равны
			res = Verylong(0L);                 // результат равен 0
	}

	return res;
}

// натуральное сложение: находим сумму двух положительных очень длинных целых чисел,
// то есть итог сложения тоже будет положительным очень длинным целым числом
// (сумма двух натуральных чисел дает натуральное число)
Verylong Verylong::addBy(const Verylong v) const
{
	wchar_t temp[SIZE];
	int j;
	// получим длину более длинного слагаемого
	int maxlen = (m_length > v.m_length) ? m_length : v.m_length;
	int carry = 0;                         // перенос станет равен 1,
										   // если сумма разрядов будет >= 10
	for (j = 0; j < maxlen; j++)           // начать цикл поразрядного сложения
	{
		int d1 = (j > m_length - 1) ? 0 : m_string[j] - L'0';     // получим цифру 1-го слагаемого
		int d2 = (j > v.m_length - 1) ? 0 : v.m_string[j] - L'0'; // получим цифру 2-го слагаемого
		int digitsum = d1 + d2 + carry;    // суммируем цифры и перенос
		if (digitsum >= 10)                // если сумма цифр >= 10, то выполнить перенос
		{
			digitsum -= 10; carry = 1;
		} // уменьшим сумму на 10 и установим перенос
		else
			carry = 0;                     // иначе переноса нет, он равен нулю
		temp[j] = digitsum + L'0';         // преобразуем цифру в символ и помещаем в итог
	}
	if (carry == 1)                        // если остался перенос от последнего сложения,
		temp[j++] = L'1';                  // добавляем еще один старший разряд, равный 1
	temp[j] = L'\0';                       // обозначим конец строки нулевым символом

	// вставим удаление ведущих нулей на всякий случай
	for (j = wcslen(temp) - 1; j > 0; j--)
	{
		if (temp[j] == L'0')               // если разряд содержит 0,
			temp[j] = L'\0';               // сократить наше число на этот разряд
										   // и перейти к проверке следующего разряда
		else
			break;                         // иначе выйти из цикла
	}

	return Verylong(temp);                 // возвратим результат сложения
}

// натуральное вычитание: находим разницу двух положительных очень длинных целых чисел,
// при этом должно выполняться условие: первое из этих чисел больше второго или равно ему,
// то есть итог вычитания тоже будет положительным очень длинным целым числом
// (разница двух натуральных чисел дает натуральное число, если уменьшаемое больше
// вычитаемого или равно ему)
Verylong Verylong::subtract(const Verylong v) const
{
	wchar_t temp[SIZE];
	int j;
	int carry = 0;                         // перенос из старшего разряда

	for (j = 0; j < m_length; j++)             // начать цикл поразрядного вычитания
	{
		int d1 = m_string[j] - L'0';                          // получим цифру уменьшаемого
		int d2 = (j > v.m_length - 1) ? 0 : v.m_string[j] - L'0'; // получим цифру вычитаемого
		int digitres = d1 - d2 - carry;    // вычисляем разность этих цифр
										   // с учетом переноса
		if (digitres < 0)                  // если разность < 0, то выполнить перенос
		{
			digitres += 10; carry = 1;
		} // увеличим разность на 10 и установим перенос
		else
			carry = 0;                     // иначе переноса нет, он равен нулю
		temp[j] = digitres + L'0';         // преобразуем цифру в символ и помещаем в итог
	}
	temp[j] = L'\0';                       // обозначим конец строки нулевым символом

	// тут в temp уже содержится результат вычитания, но в этом результате могут
	// быть ведущие нули; например, при вычислении разницы 1000 и 999 в temp
	// будет записано число 1 в виде строки "1000" (помним, что числа мы храним в
	// "перевернутом" виде), то есть с тремя ведущими нулями; поэтому здесь
	// напишем удаление этих ведущих нулей, если они есть в результате

	// ведем проверку от старшего к младшему разряду,
	// младший разряд (j == 0) проверять не будем, так как в числе должен остаться
	// хотя бы один разряд
	for (j = m_length - 1; j > 0; j--)
	{
		if (temp[j] == L'0')               // если разряд содержит 0,
			temp[j] = L'\0';               // сократить наше число на этот разряд
										   // и перейти к проверке следующего разряда
		else
			break;                         // иначе выйти из цикла
	}

	return Verylong(temp);                 // возвратим результат вычитания
}

// если текущее число больше аргумента, то возвращается 1, если меньше — 0,
// при равенстве возвращается 2 (сравниваются модули чисел, без учета знаков)
int Verylong::compare(const Verylong v) const
{
	if (m_length > v.m_length)      // кол-во разрядов текущего числа больше, чем у аргумента
		return 1;
	else if (m_length < v.m_length) // кол-во разрядов текущего числа меньше, чем у аргумента
		return 0;
	else                                    // при равном кол-ве разрядов
		for (int j = m_length - 1; j >= 0; j--) // сравним числа поразрядно,
		{                                   // начиная со старшего разряда
			if (m_string[j] - L'0' > v.m_string[j] - L'0')
				return 1;
			else if (m_string[j] - L'0' < v.m_string[j] - L'0')
				return 0;
			// если разряды равны, переходим к сравнению более младших разрядов
		}
	// если числа равны, то
	return 2;
}

// найти произведение очень длинных целых чисел
Verylong Verylong::operator* (const Verylong v)
{
	Verylong res;

	res = multiply(v);            // находим произведение модулей сомножителей
	if ((m_sign && v.m_sign) || (!m_sign && !v.m_sign)) // если сомножители имеют одинаковые знаки,
		res.m_sign = true;                        // итог — положителен
	else                                        // если сомножители имеют разные знаки,
		res.m_sign = false;                       // итог — отрицателен

	return res;
}

// натуральное умножение очень длинных целых чисел
Verylong Verylong::multiply(const Verylong v) const
{
	Verylong pprod;                        // произведение цифр из одного разряда
	Verylong tempsum;                      // текущая сумма произведений
	for (int j = 0; j < v.m_length; j++)       // переберем цифры из разрядов множителя
	{
		int digit = v.m_string[j] - L'0';     // получим цифру множителя
		pprod = multdigit(digit);          // умножим множимое на эту цифру
		for (int k = 0; k < j; k++)        // умножим результат на 10
			pprod = mult10(pprod);         // нужное количество (k) раз
		tempsum = tempsum + pprod;         // добавить очередное произведение к итоговой сумме
	}
	return tempsum;                        // возвратим результат умножения
}

// найти результат целочисленного деления очень длинных целых чисел
Verylong Verylong::operator/ (const Verylong v)
{
	Verylong res;

	res = devide(v, true);            // находим результат деления модулей
												// делимого и делителя
	if ((m_sign && v.m_sign) || (!m_sign && !v.m_sign)) // если делимое и делитель имеют одинаковые знаки,
		res.m_sign = true;                        // итог — положителен
	else                                        // если делимое и делитель имеют разные знаки,
		res.m_sign = false;                       // итог — отрицателен

	return res;
}

// найти остаток от целочисленного деления очень длинных целых чисел
Verylong Verylong::operator% (const Verylong v)
{
	Verylong res;

	if (compare(Verylong(0L)) == 2)           // если делимое равно 0
		res = Verylong(0L);               // остаток от деления равен 0
	else
	{                                     // если делимое не равно 0
		res = devide(v, false); // находим остаток от деления модулей
										  // делимого и делителя
		res.m_sign = m_sign;                  // знак остатка равен знаку делимого
	}

	return res;
}

// натуральное целочисленное деление: возвращает результат целочисленного деления, либо остаток,
// в зависимости от значения аргумента flag: true — результат, false — остаток
// (слово «натуральное» здесь означает, что делимое и делитель — положительные числа)
Verylong Verylong::devide(const Verylong v, bool flag) const
{
	if (v.compare(Verylong(0L)) == 2)          // если делитель равен 0
	{
		wcout << L"\nОшибка! Делитель не может быть равен нулю!" << endl;
		exit(1);                           // завершить программу
	}

	if (v.compare(*this) == 1)                    // если делитель больше делимого
		return (flag) ? Verylong(0L) : *this; // завершить работу метода и
											  // возвратить результат деления: 0
											  // остаток от деления: делимое

										   // если делитель меньше делимого или равен ему
	wchar_t res[SIZE];
	Verylong dividend, divider;
	int j = 0;

	dividend = *this;
	divider = v;

	dividend.m_sign = true; // так как это натуральное деление, производим его
	divider.m_sign = true;  // без учета знаков делимого и делителя

	do {                                   // цикл, пока делитель меньше делимого или равен ему

		// умножаем делитель на 10, пока он не приблизится к делимому как можно ближе
		Verylong prevdiv;
		while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			prevdiv = divider;
			divider = mult10(divider);
		}
		divider = prevdiv;

		// умножаем делитель на числа от 1 до 9, пока он не приблизится к делимому как можно ближе,
		// при этом это число в пределах от 1 до 9 станет очередной цифрой итогового ответа
		int digit = 1;
		while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2)
		{
			digit++;
			divider = prevdiv.multdigit(digit);
		}
		digit--;
		divider = prevdiv.multdigit(digit);

		// запишем найденную цифру ответа в итог
		res[j++] = digit + L'0';

		// отнимем от делимого отработанную часть
		dividend = dividend - divider;

		// вернем делитель к первоначальному значению
		divider = v;

	} while (divider.compare(dividend) == 0 || divider.compare(dividend) == 2);

	res[j] = L'\0';                           // конец строки
	_wcsrev(res);                             // перевернем итог
	return (flag) ? Verylong(res) : dividend; // возвратим результат или остаток
}

// умножение аргумента на 10
Verylong Verylong::mult10(const Verylong v) const
{
	wchar_t temp[SIZE];
	for (int j = v.m_length - 1; j >= 0; j--)  // сдвинем цифры в массиве-строке
		temp[j + 1] = v.m_string[j];          // на одну позицию вправо
	temp[0] = L'0';                        // поместим ноль в освободившуюся позицию слева
	temp[v.m_length + 1] = L'\0';              // обозначим конец строки
	return Verylong(temp);                 // возвратим результат
}

// умножение текущего числа на аргумент-цифру
Verylong Verylong::multdigit(const int d2) const
{
	wchar_t temp[SIZE];
	int j, carry = 0;
	for (j = 0; j < m_length; j++)             // переберем цифры текущего числа
	{
		int d1 = m_string[j] - L'0';          // получим цифру текущего числа
		int digitprod = d1 * d2;           // умножим ее на аргумент-цифру
		digitprod += carry;                // прибавим к произведению перенос
		if (digitprod >= 10)               // если результат >= 10, организуем перенос
		{
			carry = digitprod / 10;        // перенос равен цифре из старшего разряда
			digitprod -= carry * 10;       // текущий результат — цифра из младшего разряда
		}
		else
			carry = 0;                     // иначе перенос равен нулю (переноса нет)
		temp[j] = digitprod + L'0';        // преобразуем цифру в символ и помещаем в итог
	}
	if (carry != 0)                        // если остался перенос от последнего произведения,
		temp[j++] = carry + L'0';          // добавляем еще один старший разряд с переносом
	temp[j] = L'\0';                       // обозначим конец строки
	return Verylong(temp);                 // возвратим результат
}

