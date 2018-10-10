// Barry Yung
// Samual Martel
// Algos Project2a
#include "Deck.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

//------Deck Functions-------//



//Deck constructor
Deck::Deck()
{
    head = NULL;
    vector<string> suits = { "Clubs" , "Diamonds", "Hearts", "Spades"};
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

//destructor
 Deck::~Deck()
{
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
        rnd1 = rand()%52;   //generate two random numbers
        rnd2 = rand()%52;   
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





// Card Functions
void card::setValue(string sValue) 
{
    value = sValue;
}

void card::setSuit(string sSuit) 
{
    suit = sSuit;
}

string card::getSuit() 
{
    return suit;
}

string card::getValue() 
{
    return value;
}

card* Deck::deal()
{
    node* cursor;
    cursor = head;
    head = head->next;
    length--;
    return cursor;
}

void Deck::replace(card& card)
{
    node* cursor;
    node temp;
    temp->next = NULL;
    temp->data = card;
    cursor = head;
    int i = 1;
    while(cursor->next != NULL)
    {
        cursor = cursor->next;
    }
    cursor->next = &temp;
    length++;
    return;
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
