#include "8_5.h"


int main8_5()
{
	Time timeFirst(1, 5, 1), timeSecond(2, 4, 5);
	Time timeSum(3, 9, 6), tempTime;

	//timeSum = timeFirst + timeSecond;

	timeFirst.displayTime();
	timeSecond.displayTime();
	timeSum.displayTime(); // 3 9 6

	++timeSum; timeSum.displayTime();
	--timeSum; timeSum.displayTime();

	tempTime = timeSum++; tempTime.displayTime();
	tempTime = timeSum--; tempTime.displayTime();


	return 0;
}


//Time Time::operator+(Time time)
//{
//	long totalSeconds = (mHours * 3600) + (mMinutes * 60) +
//		mSeconds + (time.mHours * 3600) + (time.mMinutes * 60) + time.mSeconds;
//
//	int hours = totalSeconds / (60 * 60);
//	int minutes = totalSeconds % (60 * 60) / 60;
//	int seconds = totalSeconds % (60 * 60) % 60;
//
//	return Time(hours, minutes, seconds);
//}

// postfix

Time Time::operator++(int)
{
	return Time(mHours++, mMinutes++, mSeconds++);
}

Time Time::operator--(int)
{
	return Time(mHours--, mMinutes--, mSeconds--);
}

// prefix

Time Time::operator++()
{
	return Time(++mHours, ++mMinutes, ++mSeconds);
}

Time Time::operator--()
{
	return Time(--mHours, --mMinutes, --mSeconds);
}
