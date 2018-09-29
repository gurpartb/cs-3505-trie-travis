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

Trie* Trie::getCurrentTrieP(std::string s){
        Trie* currentP;
        int pos = s.at(0)-97;
        if(triePArray[pos]==NULL) {
                return NULL;
        }else{
                currentP= triePArray[pos];
        }
        for(unsigned int i = 1; i<s.size(); i++) {
                pos = s.at(i)-97;
                if(currentP->triePArray[pos]==NULL) {
                        return NULL;
                }else{
                        currentP= currentP->triePArray[pos];
                }
        }
        return currentP;
}

void Trie::allWordsInTrieP(Trie* currentP,std::string s, std::vector<std::string>* stringVectorP){
        if(currentP->isValidWord==true) {
                (*stringVectorP).push_back(s);
        }
        for(unsigned int i = 0; i<_alphabetSize; i++) {
                if(currentP->triePArray[i]!=NULL) {
                        std::string pass = s+char(i+97);
                        allWordsInTrieP(currentP->triePArray[i], pass, stringVectorP);
                }
        }
}

Trie::Trie() : isValidWord(false),triePArray(){
}

Trie::~Trie(){
        for(unsigned int i= 0; i<_alphabetSize; i++) {
                if(triePArray[i]!=NULL) {
                        delete triePArray[i];
                }
        }
}

Trie::Trie(const Trie& other) : triePArray() {
        isValidWord = other.isValidWord;
        for (unsigned int i = 0; i < _alphabetSize; i++) {
                if(other.triePArray[i]!=NULL) {
                        triePArray[i]= new Trie(*(other.triePArray[i]));
                }
        }
}

Trie& Trie::operator=(Trie other){

        std::swap(isValidWord, other.isValidWord);
        std::swap(triePArray, other.triePArray);
        return *this;
}

void Trie::addAWord(std::string s){
        if(s.size()==0) return;
        Trie* currentP;
        int pos = int(s.at(0)-97);
        if(triePArray[pos]!=NULL) {
                currentP=triePArray[pos];
        }else{
                triePArray[pos]=new Trie();
                currentP=triePArray[pos];
        }

        for(unsigned int i = 1; i<s.size(); i++) {
                pos = int(s.at(i)-97);
                if(currentP->triePArray[pos]!=NULL) {
                        currentP=currentP->triePArray[pos];
                }else{
                        currentP->triePArray[pos]=new Trie();
                        currentP=currentP->triePArray[pos];
                }
        }
        currentP->isValidWord = true;
}

bool Trie::isAWord(std::string s){
        if(s.size()==0) return false;
        Trie* currentP = getCurrentTrieP(s);
        if(currentP==NULL) {
                return false;
        }else{
                return currentP->isValidWord;
        }
}

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string s){
        Trie* currentP;
        std::vector<std::string>* stringVectorP;
        std::vector<std::string> stringVector;
        stringVectorP = &stringVector;
        if(s.size()==0) {
                currentP=this;
                allWordsInTrieP(this, s, stringVectorP);
        }else{
                currentP= getCurrentTrieP(s);
                if(currentP!=NULL) {
                        allWordsInTrieP(currentP, s, stringVectorP);
                }
        }
        return stringVector;
}
