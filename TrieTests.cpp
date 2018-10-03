#include "gtest/gtest.h"
#include "Trie.h"

TEST (WordsTest, AddWords){
  Trie trie;
  trie.addAWord("cat");
  EXPECT_EQ (true, trie.isAWord("cat"));
  EXPECT_EQ (false, trie.isAWord("ca"));
  EXPECT_EQ (false, trie.isAWord("cats"));
}

int main(int argc, char** argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
  //return 0;
}
