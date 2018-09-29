/**
 * This is Tester for the Trie class. It takes in exactly two command line arguements. Both arguments must be .txt files.
 * all words in text files must be lower case a-z and contain no special characters. This reads the first text file and builds
 * a dictionary using words in the first text file. This tester reads in the second file and checks for valid words against the
 * dictionary built using the words in the first file. All words found or not are displayed on the console with shord descriptive message.
 * [@author Gurpartap Singh Bhatti
 * @version 1.0
 * @date september 25, 2018
 * @class CS-3505 fall 2018
 * @assignment A3-Trie
 * @professor David Johnson
 */
#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "Trie.h"

int main(int argc, char* argv[]) {
        std::vector<std::string> allwords;
        std::vector<std::string>::iterator it;
        std::string word;
        Trie t1;
        if(argc<3) {
                return 0;
        }
        for(int i =0; i<argc; i++)
                std::cout << argv[i] << '\n';
        std::ifstream stream1;
        std::ifstream stream2;
        stream1.open(argv[1]);
        stream2.open(argv[2]);
        if(!stream1.is_open()) {
                std::cout <<argv[1]<< " file didn't open" << '\n';
                exit(EXIT_FAILURE);

        }
        if(!stream2.is_open()) {
                std::cout <<argv[2]<< " file didn't open" << '\n';
                exit(EXIT_FAILURE);

        }
        while(stream1.good()) {
                t1.addAWord(word);
                stream1>>word;
        }

        bool skip = true;
        while(stream2.good())
        {
                if(!skip) {
                        if(t1.isAWord(word)) {
                                std::cout << word<<" is found\n";
                        }else{
                                std::cout << word<<" is not found, did you mean:\n";
                                allwords=t1.allWordsStartingWithPrefix(word);
                                if(allwords.size()>0) {
                                        for (it=allwords.begin(); it!=allwords.end(); it++) {
                                                std::cout<<"   "<<*it<<'\n';
                                        }
                                        allwords.clear();
                                }else{
                                        std::cout <<"   no alternatives found\n";
                                }
                        }
                }
                skip = false;
                stream2>>word;
        }

        /********** TESTING RULE OF THREE. BIGLY! ************/
        Trie* tp = new Trie();
        tp->addAWord("abc");
        Trie tcopy(*tp);
        tcopy.addAWord("cat");
        if(tp->isAWord("cat")&&!tcopy.isAWord("cat")&&!tcopy.isAWord("abc")) {
                std::cout << "Copy constructor failed." << '\n';
        }
        Trie tequal;
        tequal = tcopy;
        delete tp;
        tequal.addAWord("dog");
        if(!tequal.isAWord("abc")&&tcopy.isAWord("dog")&&!tequal.isAWord("dog")) {
                std::cout << "Equal operator failed." << '\n';
        }

        stream1.close();
        stream2.close();

        return 0;
}
