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
	long totalSeconds = (m_hours * 3600) + (m_minutes * 60) +
		m_seconds + (time.m_hours * 3600) + (time.m_minutes * 60) + time.m_seconds;

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}

NewTime NewTime::operator-(const NewTime &time) const
{
	long totalSeconds = ((m_hours * 3600) + (m_minutes * 60) +
		m_seconds) - ((time.m_hours * 3600) + (time.m_minutes * 60) + time.m_seconds);

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}

NewTime NewTime::operator*(const NewTime &time) const
{
	long totalSeconds = ((m_hours * 3600) + (m_minutes * 60) +
		m_seconds) * ((time.m_hours * 3600) + (time.m_minutes * 60) + time.m_seconds);

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
	++m_seconds;
	if (m_seconds >= 60)
	{
		m_seconds = 60;
		++m_minutes;

		if (m_minutes >= 60)
		{
			m_minutes = 60;
			++m_hours;
		}
	}

	return (*this);
}

NewTime &NewTime::operator--()
{
	--m_hours;
	if (m_hours <= 0)
	{
		m_hours = 0;
		--m_minutes;
		if (m_minutes <= 0)
		{
			m_minutes = 0;
			--m_seconds;
		}
	}

	return (*this);
}
