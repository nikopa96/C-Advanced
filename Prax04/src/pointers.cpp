#include <iostream>
#include "pointers.hpp"

/**
 * Copy the sum of two integers into variable referenced by pointer c.
 * @param a a pointer to the first argument.
 * @param b a pointer to the second argument.
 */
void Pointers::sum(int * a, int *b, int *c) {
    *c = *a + *b;
}

/**
 * Copy a character sequence s, letter by letter, into buffer buf.
 * To keep things simple, you do not need to worry about buffer overflows today.
 * Hint: iterate over each character in the string and print it separately.
 * Hint: recall that the null-bute '\0' marks the end of the sequence.
 * @param s - a constant pointer to the first character in the sequence.
 */
void Pointers::copy(const char *s, char *buf) {
    while ( *s != '\0' ) { *buf++ = *s++; } /* *buf = *s; s++; buf++; */
    *buf = '\0';
}

/**
 * Write a character sequence s, letter by letter, in reverse order into buffer buf.
 * To keep things simple, you do not need to worry about buffer overflows today.
 * Hint: iterate over each character in the string and write it into buf.
 * Hint: recall that the null-bute '\0' marks the end of the sequence.
 * @param s - a read-only pointer to the first character in the sequence.
 */
void Pointers::reverse(const char *s, char* buf) {
    const char *end = s;
    while ( *end != '\0' ) { end++; }
    while ( end != s ) { *buf++ = *--end; }  /* end--; *buf = *end; buf++; */
    *buf = '\0';
}

/**
 * Calculate the number of characters in a character sequence s.
 * Requirement: do not use any counters or temporary variables to store the length of the sequence.
 * Requirement: do not use any standard library functions here. Only pointer arithmetic is permitted.
 * @param s a read-only pointer to the first character in the sequence.
 * @return the number of characters
 */
long Pointers::countLetters(const char *s) {
    const char *end = s;
    while ( *end != '\0' ) { end++; }
    return end - s;
}

/**
 * Checks if a given character sequence is a palindrome.
 * Requirement: do not use any standard library functions here. Only pointer arithmetic is permitted.
 * @param s a read-only pointer to the first character in the sequence.
 * @return true if a given sequence is a palindrome, false otherwise.
 */
bool Pointers::palindrome(const char *s) {
    const char *begin = s;
    const char *end = s;
    while ( *end != '\0' ) { end++; }
    while ( end != s ) {
        //if ( *--end != *begin++ ) return false;
         --end;
         if ( *end != *begin ) return false;
         begin++;
    }
    return true;
}

/**
 * A method gets to chratcter sequences as inputs and counts.
 * the occurrences of the characters from the second sequence.
 * in the first sequence.
 * @param s a sequence used to count the characters.
 * @param p a sequence consisting of the "interesting" characters we wish to count.
 * @return the numbe of occurrences of the symbols from the sequence p in the sequence s.
 */
unsigned int Pointers::countSymbols(const char *s, const char *p) {
    return 0;
}

/**
 * Compare two character sequences in lexicographic order.
 * @param s the first sequence.
 * @param t the second sequence.
 * @return 0, if sequences are equal, -1 if s < t, +1 otherwise.
 */
int Pointers::compare(const char *s, const char *t) {
    for ( ; ; s++, t++) {
        if ( *s == '\0' && *t == '\0' ) return 0;
        if ( *s < *t ) return -1;
        if ( *s > *t ) return 1;
    }
    return 0;
}

/**
 * Simulate binary addition, write the sum of a and b into c.
 * Requirement: you are allowed to use only binary operators:
 * binary conjunction (&), binary disjunction (|), and binary negation (~).
 * Requirement: do not use temporary variables to store bit values, except for the carry bit.
 * @param a is the first argument of type char
 * @param b is the second argument of type char
 * @param c is the placeholder for the results
 */
void Pointers::binaryAddition(const u_char *a, const u_char *b, u_char * const c) {

}
