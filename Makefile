CC = g++
SAN = -fsanitize=undefined -fsanitize=address -g
FLAGS = -Wall $(SAN)
DIR = ./
#$(FLAGS)

GOOGLEDIR = /usr/src/gtest
GOOGLEINCLUDE = /usr/src/gtest/include
# GOOGLEDIR = ./gtest
# GOOGLEINCLUDE = ./gtest/include

TrieTests: Trie.o TrieTests.o
	$(CC) -o TrieTests TrieTests.o Trie.o -pthread -L ${GOOGLEDIR} -l gtest

TrieTests.o: TrieTests.cpp
	$(CC) -c TrieTests.cpp -I ${GOOGLEINCLUDE}

Trie.o: Trie.cpp Trie.h
	$(CC) -c Trie.cpp

clean:
	rm *.o TrieTests

test: TrieTests input2.txt input3.txt
	./TrieTests input2.txt input3.txt
