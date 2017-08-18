CFLAGS = -O -std=c++11
CC = g++   
RunMe: main.o abc.o
	$(CC) $(CFLAGS) -o RunMe main.o abc.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

abc.o: abc.cpp
	$(CC) $(CFLAGS) -c abc.cpp

clean:                 
	rm -f *.o
