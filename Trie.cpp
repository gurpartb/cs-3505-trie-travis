/**
 * All comments are in the header file.
 * @author Gurpartap Singh Bhatti
 * @version 1.0
 * @date september 25, 2018
 * @class CS-3505 fall 2018
 * @assignment A3-Trie
 * @professor David Johnson
 */
#include "Trie.h"

int Trie::charToIndex(char character){
        return character-ascii_a;
}

char Trie::indexToChar(int index){
        return index+ascii_a;
}

Trie* Trie::getCurrentTrieP(std::string word){
        Trie* currentP= this;
        for(std::string::iterator it = word.begin(); it!=word.end(); it++) {
                int index = charToIndex(*it);
                if(currentP->triePArray[index])
                        currentP= currentP->triePArray[index];
                else
                        return NULL;
        }
        return currentP;
}

void Trie::allWordsInTrie(std::string word, std::vector<std::string>* wordsVectorP){
        if(isValidWord)
                wordsVectorP->push_back(word);
        for(int i = 0; i < alphabetSize; i++)
                if(triePArray[i])
                        triePArray[i]->allWordsInTrie(word+indexToChar(i), wordsVectorP);
}

Trie::Trie() : isValidWord(false),triePArray(){
}

Trie::~Trie(){
        for(int i = 0; i < alphabetSize; i++)
                delete triePArray[i];
}

Trie::Trie(const Trie& other) : triePArray() {
        isValidWord = other.isValidWord;
        for (int i = 0; i < alphabetSize; i++)
                if(other.triePArray[i])
                        triePArray[i]= new Trie(*(other.triePArray[i]));
}

Trie& Trie::operator=(Trie other){
        std::swap(isValidWord, other.isValidWord);
        std::swap(triePArray, other.triePArray);
        return *this;
}

void Trie::addAWord(std::string word){
        if(word.size() == 0)
                return;
        Trie* currentP = this;
        for(std::string::iterator it = word.begin(); it!=word.end(); it++) {
                int index = charToIndex(*it);
                if(!currentP->triePArray[index])
                        currentP->triePArray[index] = new Trie();
                currentP = currentP->triePArray[index];
        }
        currentP->isValidWord = true;
}

bool Trie::isAWord(std::string word){

        return getCurrentTrieP(word) && getCurrentTrieP(word)->isValidWord;
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string word){
        std::vector<std::string> wordsVector;
        Trie* currentP = getCurrentTrieP(word);
        if(currentP)
                currentP->allWordsInTrie(word, &wordsVector);
        return wordsVector;
}

std::vector<std::string> wordsWithWildcardPrefix(std::string word){
        std::vector<std::string> wordsVector;
        return wordsVector;
}
