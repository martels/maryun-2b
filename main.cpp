//Barry Yung
//Samual Martel
//Algos Project2a
#include "Deck.h"

using namespace std;

int main()
{
	Deck deck;
	deck.print();
	cout << endl << endl << "Shuffling Deck...." << endl << endl;
    deck.shuffle();
    deck.print();

    
	return 0;
}
