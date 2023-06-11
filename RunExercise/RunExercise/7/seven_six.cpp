#include "stdafx.h"

using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

// 2-10 default numbers
const int
	jack =  11,
	queen = 12,
	king =  13,
	ace =   14;

class Card
{
private:
	int mNumber;
	Suit suit;

public:
	Card(){}

	void set(int numb, Suit sut)
	{
		mNumber = numb;
		suit = sut;
	}

	void display();
};

// show card
void Card::display()
{
	if (mNumber >= 2 && mNumber <= 10)
		cout << mNumber;
	else 
	{
		switch (mNumber)
		{
			case jack: cout << 'J'; break;
			case queen: cout << 'Q'; break;
			case king: cout << 'K'; break;
			case ace: cout << 'A'; break;

		default: cout << "You didn't choose anything";
			break;
		}
	}
	switch (suit)
	{
	case clubs: cout << static_cast<char>(5);
		break;
	case diamonds: cout << static_cast<char>(4);
		break;
	case hearts: cout << static_cast<char>(3);
		break;
	case spades: cout << static_cast<char>(6);
		break;
	}
}

int main6()
{
	Card deck[52];
	int i;

	cout << "\n";
	// creating an ordered deck of cards 
	for (i = 0; i < 52; i++)
	{
		int number = (i % 13) + 2;
		Suit suit = Suit(i / 13);
		deck[i].set(number, suit);
	}

	// show source deck
	cout << "Source deck: \n";
	for (i = 0; i < 52; i++)
	{
		deck[i].display();
		cout << " ";
		// start a new line after every 13 cards
		if (!((i + 1) % 13)) {
			cout << endl;
		}
	}
	cout << endl;
	
	// initialize the randomizer
	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		// choosing a random card
		int randomCard = rand() % 52;
		// and change it to the current card
		Card temp = deck[i];
		deck[i] = deck[randomCard];
		deck[randomCard] = temp;
	}

	// show the shuffled deck
	cout << "The shuffled deck: \n";
	for (i = 0; i < 52; i++)
	{
		deck[i].display();
		cout << " ";
		// start a new line after every 13 cards
		if (!((i + 1) % 13)) {
			cout << endl;
		}
	}

	return 0;
}
