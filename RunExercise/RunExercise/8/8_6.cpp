#include "8_6.h"


int main8_6()
{
	NewTime timeFirst(1, 5, 1), timeSecond(2, 4, 5);
	NewTime timeSum, tempTime;

	timeSum = timeFirst + timeSecond;

	timeFirst.displayTime();
	timeSecond.displayTime();
	timeSum.displayTime(); // 3 9 6

	++timeSum; timeSum.displayTime(); // 4 10 7
	--timeSum; timeSum.displayTime(); // 3 9 6

	tempTime = timeSum++; tempTime.displayTime(); // 3 9 6
	tempTime = timeSum--; tempTime.displayTime(); // 4 10 7

	// 0:4294(237): 4294(292)
	timeSum = timeFirst - timeSecond; timeSum.displayTime();
	// 8067:29:5
	timeSum = timeFirst * timeSecond; timeSum.displayTime();


	return 0;
}


NewTime NewTime::operator+(const NewTime &time) const
{
	long totalSeconds = (m_Hours * 3600) + (m_Minutes * 60) +
		m_Seconds + (time.m_Hours * 3600) + (time.m_Minutes * 60) + time.m_Seconds;

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}

NewTime NewTime::operator-(const NewTime &time) const
{
	long totalSeconds = ((m_Hours * 3600) + (m_Minutes * 60) +
		m_Seconds) - ((time.m_Hours * 3600) + (time.m_Minutes * 60) + time.m_Seconds);

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}

NewTime NewTime::operator*(const NewTime &time) const
{
	long totalSeconds = ((m_Hours * 3600) + (m_Minutes * 60) +
		m_Seconds) * ((time.m_Hours * 3600) + (time.m_Minutes * 60) + time.m_Seconds);

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}



// postfix

NewTime NewTime::operator++(int)
{
	NewTime time;
	++(*this);
	return time;
}

NewTime NewTime::operator--(int)
{
	NewTime time;
	--(*this);
	return time;
}

// prefix

NewTime &NewTime::operator++()
{
	++m_Seconds;
	if (m_Seconds >= 60)
	{
		m_Seconds = 60;
		++m_Minutes;

		if (m_Minutes >= 60)
		{
			m_Minutes = 60;
			++m_Hours;
		}
	}

	return (*this);
}

NewTime &NewTime::operator--()
{
	--m_Hours;
	if (m_Hours <= 0)
	{
		m_Hours = 0;
		--m_Minutes;
		if (m_Minutes <= 0)
		{
			m_Minutes = 0;
			--m_Seconds;
		}
	}

	return (*this);
}
