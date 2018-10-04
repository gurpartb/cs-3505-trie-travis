#include "gtest/gtest.h"
#include "Trie.h"
#include <string>
#include <vector>

// 1. Test AddWords
TEST (Trie, AddWords){
        Trie trie;
        trie.addAWord("cat");
        EXPECT_EQ (true, trie.isAWord("cat"));
        EXPECT_EQ (false, trie.isAWord("ca"));
        EXPECT_EQ (false, trie.isAWord("cats"));
}

TEST(Trie, CopyConstructor){
        Trie trie;
        trie.addAWord("a");
        trie.addAWord("b");
        trie.addAWord("c");
        Trie copy = trie;
        EXPECT_EQ (true, copy.isAWord("a"));
        EXPECT_EQ (true, copy.isAWord("b"));
        EXPECT_EQ (true, copy.isAWord("c"));
}

TEST (Trie, EqualOverload){
        Trie trie;
        trie.addAWord("a");
        trie.addAWord("b");
        trie.addAWord("c");
        Trie copy;
        copy.addAWord("d");
        copy = trie;
        EXPECT_EQ (true, copy.isAWord("a"));
        EXPECT_EQ (true, copy.isAWord("b"));
        EXPECT_EQ (true, copy.isAWord("c"));
        EXPECT_EQ (false, copy.isAWord("d"));
}

TEST (Trie, AddDifferentWordManyTimes){
        Trie trie;
        std::string word = "";
        for(int i = 0; i < 1000; i++) {
                word += "i";
                trie.addAWord(word);
        }
        word = "";
        for(int i = 0; i < 1000; i++) {
                word += "i";
                EXPECT_EQ (true, trie.isAWord(word));
        }
}

TEST (Trie, GetAllWordsInTrie){
  Trie trie;
  std::string word = "";
  std::vector<std::string> words;
  for(int i = 0; i < 1000; i++) {
          word += "i";
          words.push_back(word);
          trie.addAWord(word);
  }
  EXPECT_EQ (words, trie.allWordsStartingWithPrefix(""));
}

TEST (Trie, GetAllWordsInTrie2){
  Trie trie;
  std::string word = "";
  char letter = 'a';
  std::vector<std::string> words;
  for(int i = 0; i < 26; i++) {
          word = letter;
          words.push_back(word);
          trie.addAWord(word);
          letter += 1;
  }
  EXPECT_EQ (words, trie.allWordsStartingWithPrefix(""));
}

TEST (Trie, GetAllWordsInTrieCopyConstructor){
  Trie trie;
  std::string word = "";
  char letter = 'a';
  std::vector<std::string> words;
  for(int i = 0; i < 26; i++) {
          word = letter;
          words.push_back(word);
          trie.addAWord(word);
          letter += 1;
  }
  Trie copy = trie;
  EXPECT_EQ (words, copy.allWordsStartingWithPrefix(""));
}

TEST (Trie, GetAllWordsInTrieEqualOverload){
  Trie trie;
  std::string word = "";
  char letter = 'a';
  std::vector<std::string> words;
  for(int i = 0; i < 26; i++) {
          word = letter;
          words.push_back(word);
          trie.addAWord(word);
          letter += 1;
  }
  Trie copy;
  word = "ab";
  for(int i = 0; i < 1000; i++){
    copy.addAWord(word);
    word += "ab";
  }
  copy = trie;
  EXPECT_EQ (words, copy.allWordsStartingWithPrefix(""));
}

int main(int argc, char** argv){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
        //return 0;
}
