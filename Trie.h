/**
 * This is a header file for the Trie class. This class builds a dictionary housing
 * lower case letter a-z. It lets user addAWord, check the word exists isAWord.
 * And acess all words starting with a prefix.
 * @author Gurpartap Singh Bhatti
 * @version 1.0
 * @date september 25, 2018
 * @class CS-3505 fall 2018
 * @assignment A3-Trie
 * @professor David Johnson
 */
#include <iostream>
#include <string.h>
#include <vector>

class Trie {
private:
bool isValidWord;
const unsigned int _alphabetSize = 26;
Trie* triePArray[26];
/**
 * [This is a helper. It returns a Trie* correspoinding to the last letter in string s.]
 * @param  s [string]
 * @return   [Trie*]
 */
Trie* getCurrentTrieP(std::string s);
/**
 * [This is a helper method that adds all words below the passed Trie* to the passed by refrence vector<string>]
 * @param currentP      [Trer*]
 * @param s             [String prefix]
 * @param stringVectorP [vector<string> passed by reference]
 */
void allWordsInTrieP(Trie* currentP,std::string s, std::vector<std::string>* stringVectorP);
public:
/**
 * Trie constructor, called to build Trie objects.
 */
Trie();
/**
 * Trie destructor, deletes all Trie pointer preventing memory leaks.
 */
~Trie();
/**
 * This is a copy constuctor. I makes a deep copy of the Trie. That is independentof the
 * Trie passed in.
 * @param other [description]
 */
Trie(const Trie& other);
/**
 * Equal operator constructs an independent deep copy of the Trie.
 * @param s [description]
 */
Trie& operator=(Trie other);
/**
 * [This is public method that adds a passed in word to the Trie dictionary.]
 * @param s [description]
 */
void addAWord(std::string s);
/**
 * [This is public method checks the Trie for passed in word. Returns true if the word is in the Trie. Else returns false.]
 * @param  s [word string]
 * @return   [boolean]
 */
bool isAWord(std::string s);
/**
 * [This is a public method that returns all words staring with prefix.
 * If words starting with prefix are not in Tris, empty vector<string> is returned.]
 * @param s [Strig prfix]
 */
std::vector<std::string> allWordsStartingWithPrefix(std::string s);
};
