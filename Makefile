flipcard: Deck.o main.o
	g++ Deck.o main.o -o flipcard

Deck.o: Deck.cpp
	g++ -Wall -c Deck.cpp

main.o: main.cpp
	g++ -Wall -c main.cpp

clean:
	rm main.o Deck.o flipcard
