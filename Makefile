<<<<<<< HEAD
CC = g++
SAN = -fsanitize=undefined -fsanitize=address
FLAGS = -Wall $(SAN)
DIR = ./

TrieTest: Trie.o TrieTest.o
	$(CC) $(FLAGS) -o TrieTest TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp
	$(CC) $(FLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(FLAGS) -c Trie.cpp

clean:
	rm *.o TrieTest
=======

test: main
	./main

main: main.cpp
	g++ -o main main.cpp
>>>>>>> b53c10efa03c895a6bdabcb960265259cca6eb6c
