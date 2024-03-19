#include "11_8.h"
#include "../msoftcon.h"

int main11_8()
{
	float length; int total;
	std::cout << "Enter the track legnth(from 1 to 12 furlongs)";
	std::cin >> length;
	std::cout << "Enter number of horse(1 t to 7)";
	std::cin >> total;

	Comtrack track(length, total);
	track.run();

	end_graphics();
}

void Horse::displayHorse(const float elapsed_time) const
{
	set_cursor_pos(1 + int(p_distanceRun * FURLONG_LENGTH), 2 + p_HORSE_NUMBER * 2);
	set_color(static_cast<color>(cRED + p_HORSE_NUMBER));

	char horseNumberDesc = '0' + static_cast<char>(p_HORSE_NUMBER);

	// If !finish
	if (p_distanceRun < p_ptrTrack->getTrackLength() + 1.0 / FURLONG_LENGTH)
	{
		// Randomly genering 1 from 3 numbers
		// 0 - horse no movement
		// 1 or 2 - moved to forward 0.2 furlongs
		if (rand() % 3)
			p_distanceRun += 0.2;
		p_finishTime = elapsed_time;
	}
	else
	{
		int min = int(p_finishTime) / 60;
		int sec = int(p_finishTime) - min * 60;
		std::cout << "Time: " << min << "." << sec<<"\n";
	}
}

void Comhorse::displayHorse(const float elapsed_time) const
{
	set_cursor_pos(1 + int(p_distanceRun * FURLONG_LENGTH), 2 + p_HORSE_NUMBER * 2);
	set_color(static_cast<color>(cYELLOW + p_HORSE_NUMBER));

	char horseNumberDesc = '0' + static_cast<char>(p_HORSE_NUMBER);

	// If !finish
	if (p_distanceRun < p_ptrTrack->getTrackLength() + 1.0 / FURLONG_LENGTH)
	{
		float moveSpeed = 0.2f;

		if (p_distanceRun >= p_ptrTrack->getTrackLength() / 3)
		{
			// If > 1 horse participate in the race
			if (p_ptrTrack->p_totalHorses > 1)
			{
				int leaderHorse, secondHorse;

				if (p_ptrTrack->p_ptrArray[0]->p_distanceRun < p_ptrTrack->p_ptrArray[1]->p_distanceRun)
				{
					leaderHorse = 1;
					secondHorse = 0;
				}
				else
				{
					leaderHorse = 0;
					secondHorse = 1;
				}

				for (int j = 2; j < p_ptrTrack->p_totalHorses; j++)
				{
					if (p_ptrTrack->p_ptrArray[leaderHorse]->p_distanceRun <
						p_ptrTrack->p_ptrArray[j]->p_distanceRun)
					{
						secondHorse = leaderHorse;
						leaderHorse = j;
					}
					else if (ptrTrack->p_ptrArray[secondHorse]->p_distanceRun <
						p_ptrTrack->p_ptrArray[j]->p_distanceRun)
						secondHorse = j;
				}

				// If horse is the leader
				if (p_distanceRun == p_ptrTrack->p_ptrArray[leaderHorse]->p_distanceRun ||
					p_distanceRun == p_ptrTrack->p_ptrArray[secondHorse])
				{
					if (p_ptrTrack->p_ptrArray[leaderHorse]->p_distanceRun - p_ptrTrack->p_ptrArray[secondHorse]->p_distanceRun <= 0.1f)
					{
						moveSpeed = 0.3f;
					}
				}

			}

			if (rand() % 3)
				p_distanceRun += moveSpeed;

			p_finishTime = elapsed_time;
		}
		else
		{
			int min = int(p_finishTime) / 60;
			int sec = int(p_finishTime) - min * 60;
			std::cout << "Time: " << min << "." << sec << "\n";
		}
	}


}

Track::Track(float lengthTrack, int numberOfHorse)
{
	init_graphics();
	p_totalHorses = (p_totalHorses > MAX_HORSES) ? MAX_HORSES : p_totalHorses;

	for (int i = 0; i < p_totalHorses; i++)
		p_ptrArray[i] = new Horse(p_horseCount++, this);

	time_t atime;
	srand(static_cast<unsigned>(time(&atime)));
	displayTrack();
}

Comtrack::Comtrack(float lengthTrack, int numberOfHorse) :Track(lengthTrack, numberOfHorse),
m_horseCount(0)
{
	for (int i = 0; i < p_totalHorses; i++)
		p_ptrArray[i] = new Comhorse(m_horseCount++, this);
}

Track::~Track()
{
	for (int i = 0; i < p_totalHorses; i++)
		delete p_ptrArray[i];
}

Comtrack::~Comtrack()
{
	for (int i = 0; i < p_totalHorses; i++)
		delete p_ptrArray[i];
}

void Track::displayTrack() const
{
	clear_screen();;
	for (int f = 0; f <= p_TRACK_LENGTH; f++) 
		for (int r = 1; r <= p_totalHorses * 2 + 1; r++) 
		{
			set_cursor_pos(f * FURLONG_LENGTH + 5, r);  
			if (f == 0 || f == p_TRACK_LENGTH) 
				std::cout << '\x2590';        
			else
				std::cout << '\x2502';         
		}
}


void Track::run()
{
	while (!_kbhit())
	{
		p_elapsedTime += 1.75;
		for (int i = 0; i < p_totalHorses; i++)
			p_ptrArray[i]->displayHorse(p_elapsedTime);

		wait(5000);
	}std::cout << "\n";
}

void Comtrack::run()
{
	while (!_kbhit())
	{
		p_elapsedTime += 1.75;
		for (int i = 0; i < p_totalHorses; i++)
			p_ptrArray[i]->displayHorse(p_elapsedTime);

		wait(5000);
	}std::cout << "\n";
}

float Track::getTrackLength() const
{
	return p_TRACK_LENGTH;
}