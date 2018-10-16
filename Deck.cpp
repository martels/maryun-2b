// Barry Yung
// Samual Martel
// Algos Project2a
#include "Deck.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>


using namespace std;

//------Deck Functions-------//



//Deck constructor
Deck::Deck()
{
    head = NULL;
    vector<string> suits = { "Clubs", "Diamonds", "Hearts", "Spades"};
    vector<string> values = { "K", "Q", "J", "10", "9", "8", "7", "6", "5", "4", "3", "2", "A" };
        
    for (int i = 0; i < 4; i++)//4 suits
    {
       for (int j = 0; j < 13; j++) //13 values
       {
           card* Card = new card(values[j], suits[i]);
           addCard(*Card);
       }
    }
}

Deck::Deck(int place)
{
    head = NULL;
    length = 0;
    
}

//destructor
 Deck::~Deck()
{
    Node* cursor;
    Node* prev;
    cursor = this->head->next;
    prev = this->head;
    while(cursor)
    {
        delete prev->data;
        delete prev->next;
        prev = cursor;
        cursor = cursor->next;
    }
    cout << "Deleted Deck" << endl;
}

//puts each card into the linked list Deck
void Deck::addCard(card& card)
{
    Node* node = new Node();
    node->data = &card;
    node->next = this->head;
    this->head = node;
};

//Shuffles Deck
void Deck::shuffle()
{
    srand(time(0)); //time for rand()
    vector<card*> temp; //temp vector to hold
    temp.resize(52);
    Node* cursor = head;
    int rnd1, rnd2;
    card* ex1;
    card* ex2;
    
    for(int i = 0; i < 52; i++) // iterate though linked list to put into vector
    {
        temp.at(i) = cursor->data;
        cursor = cursor->next;
    }

    for(int i = 0; i < 1000; i++)
    {
        rnd1 = rand() % 52;   //generate two random numbers
        rnd2 = rand() % 52;   
        ex1 = temp.at(rnd1); //take the cards at the numbers
        ex2 = temp.at(rnd2);
        
        temp.at(rnd1) = ex2;    //swap the numbers
        temp.at(rnd2) = ex1;    
    }

    cursor = head;
    for(int i = 0; i < 52; i++) //place vector back into linked list
    {
        cursor->data = temp.at(i);
        cursor = cursor->next;
    }
    
}


void Deck::print() 
{
     Node* head = this->head;
     int i = 1;
     while (head) {
         card* card = head->data;
         cout << "Card " << i << ": " << (*card).getValue() << " of " << (*card).getSuit() << endl;
         head = head->next;
         i++;
     }
 }
card Deck::flip()
{
    card* temp;
    int x;
    cout << "Which number card do you want to flip: \n";
    cin >> x;
    Node* head = this->head;
    int i = 1;
    card* p;
    //int size = sizeof(prev) / sizeof(card);
    while (head) {
        card* card = head->data;
        if (i == x){
          //  p = find(prev, size, (*card).getValue())
           // temp = card;
            cout << "Card " << i << ": " << (*card).getValue() << " of " << (*card).getSuit() << endl;
        }
        head = head->next;
        i++;
    }
    return (*temp);
}
card* Deck::deal()
{
    Node* cursor;
    cursor = this->head;
    this->head = this->head->next;
    length--;
    return cursor->data;
}

void Deck::replace(card *card)
{
    Node* cursor;
    Node* temp;
    temp->next = NULL;
    temp->data = card;
    cursor = this->head;
    int i = 1;
    while(cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    cursor->next = temp;
    length++;
    return;
}
/*int points(const card& card, int& points)
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
}*/

/*void playflip()
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
*/



//---------Card Functions---------//

card::card(card& card)
{
    suit = card.getSuit();
    value = card.getValue();
}

void card::setValue(string sValue) 
{
    value = sValue;
}

void card::setSuit(string sSuit) 
{
    suit = sSuit;
}



/*ostream& operator<<(ostream& os,card& card) {
    Node* node = new Node();
    node->data = &card;
    Node* test;
    for (node = node->data;  != 0; node = node->next){
    os << "Card: " << head->data << " of " << head->data << ".\n";
    }
    return os;
}*/


//----------Hand Fucntions----------//


