#ifndef PRAX04_H
#define PRAX04_H

// typedef unsigned char u_char;
// using u_char = unsigned char;

class Pointers {
public:
    static void sum(int *a, int *b, int *c);
    static void copy(const char *s, char* buf);
    static void reverse(const char* s, char* buf);
    static long countLetters(const char *s);
    static bool palindrome(const char* s);
    static int compare(const char* s, const char* t);
    static unsigned int countSymbols(const char *s, const char *p);
    static void binaryAddition(const u_char * a, const u_char * b, u_char * c);
};

#endif //PRAX04_H
