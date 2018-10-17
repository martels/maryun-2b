// Barry Yung
// Samual Martel
// Algos Project2a
#include "Deck.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <cmath>


using namespace std;

//--------Global-------------//

// Returns the number points that the player has after they selected the passed card
int points(const card& card, int& points)
{
    double temp = 0;
    if(card.getValue() == "A")
        points = points + 10;

    else if(card.getValue() == "K" || card.getValue() == "Q" || card.getValue() == "J")
        points = points + 5;

    else if(card.getValue() == "7")
    {
        // type casting temp from points so that ceil will function properly
        temp = double (points);
        temp = temp/2;
        points = ceil(temp);
    }
    else if(card.getValue() == "2" || card.getValue() == "3" || card.getValue() == "4" || card.getValue() == "5" || card.getValue() == "6")
        points = 0;

    if(card.getSuit() == "Hearts")
        points++;
    
    return points;
}

void playflip()
{
    //declare the deck and the hand
    Deck deck;
    Deck Hand(0);
    //initialise the selection to end game
    char sel = 'y';
    //points start from 0
    int tally = 0;
    //temporary card
    card temp;

    // deck.print();
    // cout << endl << endl;
    
    //shuffles the deck 3 times
    for(int i = 0; i < 3; i++)
    {
        deck.shuffle();
        i++;
    }

    // deck.print();
    // cout << "\n\n";
    
    //deals 24 cards into the hand
    for (int i = 0; i<24; i++)
    {
        Hand.addCard(*(deck.deal()));
    }

    // Hand.print();
    // cout << "\n\n";
    
    //while the player still wants to continue
    while (sel != 'n')
    {
        temp = Hand.flip();
        tally = points(temp, tally);
        
        cout << "You have " << tally << " points.\n";
        cout << "Would you like to flip again ('y' for yes, else for no)? ";
        cin >> sel;
    }
    
    cout << endl << endl << endl << "Thank you for playing. Your score is " << tally << endl << endl;
    return;
    
}





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
           //card temp(values[j], suits[i]);
           addCard(*Card);
       }
    }
}
//Alternate Constructor
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
    if(head == NULL)
    {
        this->head = node;
        node->next = NULL;
    }
    else
    {
 //   node->data = &card;
    node->next = this->head;
    this->head = node;
    }
}

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

//Prints the whole deck
void Deck::print()
{
     Node* cursor = this->head;
     int i = 1;
     while (cursor) {
         card* card = cursor->data;
         cout << "Card " << i << ": " << (*card).getValue() << " of " << (*card).getSuit() << endl;
         cursor = cursor->next;
         i++;
     }
 }

//returns the card at location x as well as displaying on the screen
card Deck::flip()
{
    card* temp;
    temp = new card;
    int x;
    cout << "Which number card do you want to flip: \n";
    cin >> x;
    
    Node* cursor = this->head;
    int i = 1;
    //iterate through the list, when the card number equals x output the card and set temp equal to the card
    while (cursor) {
        card* card = cursor->data;
        if (i == x){
            temp=card;
            cout << "Card " << i << ": " << (*card).getValue() << " of " << (*card).getSuit() << endl;
        }
        cursor = cursor->next;
        i++;
    }
    //return temp
    return (*temp);
}

//Deals one card off the top of the deck
card* Deck::deal()
{
    Node* cursor;
    cursor = this->head;
    this->head = this->head->next;
    length--;
    return cursor->data;
}

//Adds one card back into the deck at the bottom
void Deck::replace(card *card)
{
    Node* cursor;
    Node* temp;
    temp = new Node;
    temp->next = NULL;
    temp->data = card;
    //incase the deck is empty
    if(head == NULL)
    {
        this->head = temp;
        temp->next = NULL;
    }
    
    else{
        cursor = this->head;
        while(cursor->next != NULL)
        {
        cursor = cursor->next;
        }
    }
    cursor->next = temp;
    length++;
    return;
}















//---------Card Functions---------//
//copy constructor
card::card(card& card)
{
    suit = card.getSuit();
    value = card.getValue();
}


//set functions
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

