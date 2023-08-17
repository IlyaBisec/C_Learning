#include "8_5.h"


int main8_5()
{
	Time timeFirst(1, 5, 1), timeSecond(2, 4, 5);
	Time time4, tempTime;

	time4.addTime(timeFirst, timeSecond);
	std::cout << "add: ";
	time4.displayTime(); std::cout << "\n";
	
	tempTime = timeFirst + timeSecond;
	std::cout << "+: ";
	tempTime.displayTime(); std::cout << "\n";

	Time tFive, TSix;
	
	// ++

	tFive = ++time4;
	std::cout << "++5: ";
	tFive.displayTime(); std::cout << "\n";
	std::cout << "++4: ";
	time4.displayTime(); std::cout << "\n";
	
	TSix = tempTime++;
	std::cout << "6++: ";
	TSix.displayTime(); std::cout << "\n";
	std::cout << "temp++: ";
	tempTime.displayTime(); std::cout << "\n";

	// --

	tFive = --time4;
	std::cout << " --5: ";
	tFive.displayTime(); std::cout << "\n";
	std::cout << "--4: ";
	time4.displayTime(); std::cout << "\n";

	TSix = tempTime--;
	std::cout << "6--: ";
	TSix.displayTime(); std::cout << "\n";
	std::cout << "temp--: ";
	tempTime.displayTime(); std::cout << "\n";

	return 0;
}



long Time::convertTimeToSeconds() const
{
	return (m_Hours * 3600 + m_Minutes * 60 + m_Seconds);
}

void Time::convertSecondsToTime(long inputSeconds)
{
	m_Hours = inputSeconds / 3600;
	m_Minutes = (inputSeconds % 3600) / 60;
	m_Seconds = (inputSeconds % 3600) % 60;
}

// Adding two given times and storing the result
void Time::addTime(const Time &time1, const Time &time2)
{
	long total;

	total = time1.convertTimeToSeconds() + time2.convertTimeToSeconds();
	convertSecondsToTime(total);
}


// Unary operations
Time Time::operator+(const Time &time) const
{
	long total;

	total = convertTimeToSeconds() + time.convertTimeToSeconds();
	return Time(total);
}

// Postfix

Time Time::operator++(int)
{
	long total, temp;
	total = convertTimeToSeconds();
	temp = total++;
	convertSecondsToTime(total);

	return Time(temp);
}

Time Time::operator--(int)
{
	long total, temp;
	total = convertTimeToSeconds();
	temp = total--;
	convertSecondsToTime(total);

	return Time(temp);

	//return Time(m_Hours--, m_Minutes--, m_Seconds--);
}

// Prefix

Time Time::operator++()
{
	long total, temp;
	total = convertTimeToSeconds();
	temp = ++total;
	convertSecondsToTime(total);

	return Time(temp);
	//return Time(++m_Hours, ++m_Minutes, ++m_Seconds);
}

Time Time::operator--()
{
	long total, temp;
	total = convertTimeToSeconds();
	temp = --total;
	convertSecondsToTime(total);
	
	return Time(temp);
	//return Time(--m_Hours, --m_Minutes, --m_Seconds);
}
