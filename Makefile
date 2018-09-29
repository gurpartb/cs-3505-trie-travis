CC = g++
SAN = -fsanitize=undefined -fsanitize=address
FLAGS = -Wall $(SAN)
DIR = ./

TrieTest: Trie.o TrieTest.o
	$(CC) -o TrieTest TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp
	$(CC) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) -c Trie.cpp

clean:
	rm *.o TrieTest
