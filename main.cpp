//Barry Yung
//Samual Martel
//Algos Project2a
#include "Deck.h"
#include <cmath>
#include <math.h>

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
    deck.print();
    
    cout << endl << endl;
    while(i != 3)
    {
        deck.shuffle();
        i++;
    }
    deck.print();
    cout << "\n\n";
    for (int i = 0; i<24; i++)
    {
        Hand.addCard(*(deck.deal()));
    }
    Hand.print();
    cout << "\n\n";
    while (sel != 'n')
    {
        temp = Hand.flip();
        //attempts.push_front(temp);
        tally = points(temp, tally);
        
        cout << "You have " << tally << " points.\n";
        cout << "Would you like to flip again?";
        cin >> sel;
    }
    
    cout << " \n\n\n Thank you for playing. Your score is " << tally;
    return;
    
}

int points(const card& card, int& points)
{
    double temp = 0;
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
        temp = double (points);
        temp = temp/2;
        points = ceil(temp);
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
