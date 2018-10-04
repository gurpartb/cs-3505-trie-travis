#include "gtest/gtest.h"
#include "Trie.h"
#include <string>

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

int main(int argc, char** argv){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
        //return 0;
}
