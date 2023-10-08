// Bridge card game

#include "..\stdafx.h"

using namespace std;

enum class Suit { k_Clubs, k_Diamonds, k_Hearts, k_Spades };

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
		m_number = number;
		suit = sut;
	}
	void display();

private:
	int m_number;
	Suit suit;

};

// Show card
void Card::display()
{
	if (m_number >= 2 && m_number <= 10)
		cout << m_number;
	else 
	{
		switch (m_number)
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
	case Suit::k_Clubs: cout << static_cast<char>(5);
		break;
	case Suit::k_Diamonds: cout << static_cast<char>(4);
		break;
	case Suit::k_Hearts: cout << static_cast<char>(3);
		break;
	case Suit::k_Spades: cout << static_cast<char>(6);
		break;
	}
}

int main7_6()
{
	Card deck[52];
	int i;

	cout << "\n";
	// Creating an ordered deck of cards 
	for (i = 0; i < 52; i++)
	{
		int number = (i % 13) + 2;
		Suit suit = Suit(i / 13);
		deck[i].set(number, suit);
	}

	// Show source deck
	cout << "Source deck: \n";
	for (i = 0; i < 52; i++)
	{
		deck[i].display();
		cout << " ";
		// Start a new line after every 13 cards
		if (!((i + 1) % 13)) {
			cout << endl;
		}
	}
	cout << endl;
	
	// Initialize the randomizer
	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		// Choosing a random card
		int randomCard = rand() % 52;
		// and change it to the current card
		Card temp = deck[i];
		deck[i] = deck[randomCard];
		deck[randomCard] = temp;
	}

	// Show the shuffled deck
	cout << "The shuffled deck: \n";
	for (i = 0; i < 52; i++)
	{
		deck[i].display();
		cout << " ";
		// Start a new line after every 13 cards
		if (!((i + 1) % 13)) {
			cout << endl;
		}
	}

	return 0;
}
