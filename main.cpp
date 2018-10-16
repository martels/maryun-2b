//Barry Yung
//Samual Martel
//Algos Project2a
#include "Deck.h"

using namespace std;
void playflip();
int points(const card& card, int& points);

int main()
{
    playflip();
    return 0;
}

void playflip()
{
    Deck deck;
    Deck Hand(0);
    int i = 0;
    char sel = 'y';
    int tally = 0;
    card temp;
    
    while(i != 3)
    {
        deck.shuffle();
        i++;
    }
    
    for (int i = 0; i<24; i++)
    {
        Hand.replace(deck.deal());
    }
    
    while (sel != 'n')
    {
        //temp = deck.flip(attempts);
        //attempts.push_front(temp);
        points(temp, tally);
        
        cout << "You have " << tally << " points.\n";
        cout << "Would you like to play again?";
        cin >> sel;
    }
    
    cout << " \n\n\n Thank you for playing. Your score is " << tally;
    return;
    
}

int points(const card& card, int& points)
{
    
    if(card.getValue() == "A")
    {
        points = points + 10;
    }
    else if(card.getValue() == "K" || card.getValue() == "Q" || card.getValue() == "J")
    {
        points = points + 5;
    }
    else if(card.getValue() == "7")
    {
        points = points/2;
    }
    else if(card.getValue() == "2" || card.getValue() == "3" || card.getValue() == "4" || card.getValue() == "5" || card.getValue() == "6")
    {
        points = 0;
    }
    if(card.getSuit() == "Hearts")
    {
        points++;
    }
    return points;
}
