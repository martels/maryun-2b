//Barry Yung
//Samual Martel
//Algos Project2a
#include "Deck.h"

void playflip();

int main()
{
	playflip();
	return 0;
}


void playflip()
{
    Deck deck;
    Deck hand(0);
    int i = 0;
    int tally = 0;
    char sel = 'y';
    card temp;
    vector<card> attempts = {temp};

    while(i != 3)
    {
        deck.shuffle;
        i++;
    }

    for(int i = 0; i < 24; i++)
    {
        hand.replace(deck.deal());
    }
    while(sel != 'n')
    {
        temp = deck.flip();
//        attempts.push_front(temp);
        points(temp, tally);

        cout << "You have " << tally << "points." << endl;
        cout << "would you like to flip another card?" << endl;
        cin >> sel;
    }
    cout << endl << endl << endl << "Thank you for playing your final score was: " << tally << endl;
    cout << "goodbye" << endl;
    return;
}
