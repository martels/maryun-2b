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


//Copy constructor
card::card(card& card)
{
    suit = card.getSuit();
    value = card.getValue();
}

//Set functions
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



