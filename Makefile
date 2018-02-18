CFLAGS = -O1 -std=c++11
CC = g++

all: RunMe

RunMe: main.o pokerhand.o card.o deck.o
	$(CC) $(CFLAGS) -o RunMe main.o pokerhand.o card.o deck.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

pokerhand.o: pokerhand.cpp
	$(CC) $(CFLAGS) -c pokerhand.cpp

card.o: card.cpp
	$(CC) $(CFLAGS) -c card.cpp

deck.o: deck.cpp
	$(CC) $(CFLAGS) -c deck.cpp	

clean:                 
	rm -f *.o
