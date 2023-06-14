// Bridge card game

#include "..\stdafx.h"

using namespace std;

enum Suit { k_Clubs, k_Diamonds, k_Hearts, k_Spades };

// 2-10 default numbers
const int
	jack =  11,
	queen = 12,
	king =  13,
	ace =   14;

class Card
{
public:
	Card(){}

	void set(int number, Suit sut)
	{
		m_Number = number;
		suit = sut;
	}
	void display();

private:
	int m_Number;
	Suit suit;

};

// show card
void Card::display()
{
	if (m_Number >= 2 && m_Number <= 10)
		cout << m_Number;
	else 
	{
		switch (m_Number)
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
	case k_Clubs: cout << static_cast<char>(5);
		break;
	case k_Diamonds: cout << static_cast<char>(4);
		break;
	case k_Hearts: cout << static_cast<char>(3);
		break;
	case k_Spades: cout << static_cast<char>(6);
		break;
	}
}

int main7_6()
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
