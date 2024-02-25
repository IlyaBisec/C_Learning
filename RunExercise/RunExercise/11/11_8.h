#pragma once

#include <io.h>  
#include <cstdlib>
#include <ctime> 

const int IMG = 5;
const int MAX_HORSES = 7;

class Track;
class Comtrack;

class Horse
{
public:
	Horse(const int n, const Track *ptrT) :
		HORSE_NUMBER(n),
		ptr_track(ptrT),
		distanceRun(0.0) 
	{
	}

	~Horse()
	{
	}
	
	void display_horse(const float elapsed_time);
protected:
	const Track *ptr_track;
	const int HORSE_NUMBER;
	
	float finishTime;
	float distanceRun;
};

class Comhorse : public Horse
{
public:
	ComHorse(const int n, const Comtrack *ptrT) :horse(n, NULL),
		ptrTrack(ptrT)
	{
	}
	void display_horse(const float elapsed_time);
private:
	const Comtrack *ptr_track;

};

class Track // класс, представляющий скаковой трек
{
public:

	Track(float lenT, int nH);
	~Track();
	void display_track();     
	void run();                 
	float get_track_len() const; 

protected:
	Horse *hArray[MAX_HORSES];
	int total_horses;
	int horse_count;

	const float TRACK_LANGTH;
	float elapsed_time;
};

class Comtrack : public Track 
{
private:
	Comhorse *hArray[MAX_HORSES]; 
	int horse_count;
public:

	Comtrack(float lenT, int nH);
	~Comtrack();            
	void run();               

	friend void Comhorse::display_horse(float);
};