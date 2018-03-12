#include <gtest/gtest.h>
#include "pointers.hpp"

TEST (Pointers, sum) {
    int a = 2, b = 3, c = 5, d = 9, x, y;
    Pointers::sum(&a,&c,&x);
    Pointers::sum(&b,&d,&y);
    EXPECT_EQ(7, x);
    EXPECT_EQ(12, y);
}

TEST (Pointers, countLetters) {
    EXPECT_EQ (13, Pointers::countLetters("Hello, World!"));
    EXPECT_EQ (5, Pointers::countLetters("Hello"));
}

TEST (Pointers, copy) {
    const char *s = "Hello, World!";
    char buf[strlen(s)+1]; memset(buf,0,sizeof(buf));
    Pointers::copy(s,buf);
    EXPECT_EQ(0, strcmp(s,buf));
}

TEST (Pointers, reverse) {
    const char *s = "Hello, World!";
    char buf[strlen(s)+1]; memset(buf,0,sizeof(buf));
    Pointers::reverse(s,buf);
    EXPECT_EQ (0, strcmp("!dlroW ,olleH",buf));
}

TEST (Pointers, findCharacters) {
    EXPECT_EQ (2, Pointers::countSymbols("Hello, World!",",.!?"));
    EXPECT_EQ (16, Pointers::countSymbols("[!<DOCTYPE XML>]?version=1.0,url=http://www.google.com/","()[]{}<>!:.,*?=_/"));
    EXPECT_EQ (11, Pointers::countSymbols("std::static_cast<int**>(x){}","()[]{}<>!:.,*?=_/"));
}

TEST (Pointers, isPalindrome) {
    EXPECT_TRUE(Pointers::palindrome("level"));
    EXPECT_TRUE(Pointers::palindrome("noon"));
    EXPECT_TRUE(Pointers::palindrome("n00n"));
    EXPECT_FALSE(Pointers::palindrome("palindrome"));
    EXPECT_FALSE(Pointers::palindrome("Level"));
    EXPECT_FALSE(Pointers::palindrome("N00n"));
}

TEST (Pointers, compareSequences) {
    EXPECT_EQ(-1, Pointers::compare("hello","world"));
    EXPECT_EQ(1, Pointers::compare("there","is"));
    EXPECT_EQ(0, Pointers::compare("cargo","cargo"));
    EXPECT_EQ(-1, Pointers::compare("inv","investments"));
    EXPECT_EQ(1, Pointers::compare("investments","invest"));
    EXPECT_EQ(-1, Pointers::compare("hey","heya"));
}

TEST (Pointers, binaryAddition) {
    u_char a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, r;
    Pointers::binaryAddition(&a,&a,&r); EXPECT_EQ(a, r);
    Pointers::binaryAddition(&a,&b,&r); EXPECT_EQ(b, r);
    Pointers::binaryAddition(&b,&a,&r); EXPECT_EQ(b, r);
    Pointers::binaryAddition(&b,&b,&r); EXPECT_EQ(c,r);
    Pointers::binaryAddition(&b,&c,&r); EXPECT_EQ(d,r);
    Pointers::binaryAddition(&c,&b,&r); EXPECT_EQ(d,r);
    Pointers::binaryAddition(&c,&c,&r); EXPECT_EQ(e,r);
    Pointers::binaryAddition(&c,&d,&r); EXPECT_EQ(f,r);
    Pointers::binaryAddition(&d,&c,&r); EXPECT_EQ(f,r);
    Pointers::binaryAddition(&c,&e,&r); EXPECT_EQ(g,r);
    Pointers::binaryAddition(&e,&c,&r); EXPECT_EQ(g,r);
}