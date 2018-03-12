#include <gtest/gtest.h>
#include "pointers.hpp"

int main(int argc, char **argv) {

    ::testing::InitGoogleTest(&argc, argv);
    int x = RUN_ALL_TESTS();

    char buf[1024];
    Pointers::copy("Hello, World!",buf);
    std::cout << buf << std::endl;

    Pointers::reverse("Hello, World!",buf);
    std::cout << buf << std::endl;

    std::cout << Pointers::countLetters("Hello, World!") << std::endl;

    std::cout << Pointers::palindrome("level") << "\t"
              << Pointers::palindrome("palindrome") << std::endl;

    std::cout << Pointers::compare("Hello","Hello") << "\t"
              << Pointers::compare("Hell","Hello") << "\t"
              << Pointers::compare("Alice","Bob") << "\t"
              << Pointers::compare("Hello","Hell") << "\t"
              << Pointers::compare("Bob","Alice") << std::endl;


    return 0;
}