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


NewTime NewTime::operator+(NewTime time)
{
	long totalSeconds = (mHours * 3600) + (mMinutes * 60) +
		mSeconds + (time.mHours * 3600) + (time.mMinutes * 60) + time.mSeconds;

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}

NewTime NewTime::operator-(NewTime time)
{
	long totalSeconds = ((mHours * 3600) + (mMinutes * 60) +
		mSeconds) - ((time.mHours * 3600) + (time.mMinutes * 60) + time.mSeconds);

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}

NewTime NewTime::operator*(NewTime time)
{
	long totalSeconds = ((mHours * 3600) + (mMinutes * 60) +
		mSeconds) * ((time.mHours * 3600) + (time.mMinutes * 60) + time.mSeconds);

	int hours = totalSeconds / (60 * 60);
	int minutes = totalSeconds % (60 * 60) / 60;
	int seconds = totalSeconds % (60 * 60) % 60;

	return NewTime(hours, minutes, seconds);
}



// postfix

NewTime NewTime::operator++(int)
{
	return NewTime(mHours++, mMinutes++, mSeconds++);
}

NewTime NewTime::operator--(int)
{
	return NewTime(mHours--, mMinutes--, mSeconds--);
}

// prefix

NewTime NewTime::operator++()
{
	return NewTime(++mHours, ++mMinutes, ++mSeconds);
}

NewTime NewTime::operator--()
{
	return NewTime(--mHours, --mMinutes, --mSeconds);
}
