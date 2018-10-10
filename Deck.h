//Barry Yung
//Samual Martel
//9 OCT 2018
//Algos Project2a
#ifndef Deck_h
#define Deck_h

#include <iostream>
#include <stdio.h>


using namespace std;


class card
{
    
public:
    card(string sValue, string sSuit) {value = sValue; suit = sSuit;};              //class constructor
    void setValue(string sValue);                                                   //sets value to the passed value
    void setSuit(string sSuit);                                                     //sets suit to passed suit
    string getSuit();                                                               //returns suit
    string getValue();                                                              //returns value

private:
    string value;  
    string suit;
};

class Node 
{
     public:
        Node() {};
        Node* next;                                                                //pointer to the next value in the list
        card* data;     
};
 

class Deck 
{
    public:
        Node* head;                                                                 //head of the list
        int length;                                                                 //length of the list
        Deck();                                                                     //class constructor
        ~Deck();                                                                    //class deconstrutor
        void addCard(card& card);                                                   //adds the passed card address
        void shuffle();                                                             //shuffles the cards
        void print();                                                               //prints out the deck
        card* deal();                                                               //deals a card, removing from the deck    
        void replace(card& card);                                                   //puts card on the bottom of the deck
};



#endif
