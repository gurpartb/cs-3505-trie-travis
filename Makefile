CC = g++
SAN = -fsanitize=undefined -fsanitize=address -g
FLAGS = -Wall $(SAN)
DIR = ./
#$(FLAGS)

TrieTest: Trie.o TrieTest.o
	$(CC) -o TrieTest TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp
	$(CC) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) -c Trie.cpp

clean:
	rm *.o TrieTest

test: TrieTest input2.txt input3.txt
	./TrieTest input2.txt input3.txt
