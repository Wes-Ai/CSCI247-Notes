#include <stdio.h>

int main() {
    char s[50];
    scanf("%s", s);
    printf("You entered %s\n", s);

    char* t = s;
    printf("t=%s\n", t);

    t[0] = 'W';     // t points to the same place as s, changes s also
    printf("t=%s\n", t);
    printf("s=%s\n", s);

    int x = 0xa3;   // Hexadecimal number a3
}
//  Decimal: base 10

//      3 2 9 6 . 5 7 (base 10)
//    = 3x10^3 + 2x10^2 + 9x10^1 + 6x10^0 + 5x10^-1 + 7x10^-2


//  Binary: base 2

//  1 0 0 1 . 1 0 1 (base 2)
//  1x2^3 + 0x2^2 + 0x2^1 + 1x2^0 + 1x2^-1 + 0x2^-2 + 1x2^-3


//  Hexadecimal: base 16

//  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e, f
//  a3.b6
//  16^1 + 16^0 + 16^-1 + 16^-2
//  10x16^1 + 3x16^0 + 11x16^-1 + 6x16^-2
//  == 160 + 3 + 11/16 + 6/16^2



//      int n = 3296;   Convert to binary
//      int m = 9;
//      while(n>0) {
//          int d = n % 2; <== Base 2, 10, 16 (16 requires some code for letters)
//          n /= 2;        <==
//      }

// == 6 9 2 3 (reversed)


//      * * * NUMBER REPRESENTATIONS * * *
// char - 1 byte - 8 bits
// int - 4 bytes - 32 bits

// Decimal
// 0, 1, 2, 3, 4, 5, 6, 7, 8
// Binary
// 0000, 0001, 0010, 0011, 0100, 0101, 0110, 0111, 1000
// Hex
// 0, 1, 2, 3, 4, 5, 6, 7, 8

// Decimal
// 9, 10, 11, 12, 13, 14, 15
// Binary
// 1001, 1010, 1011, 1100, 1101, 1110, 1111
// Hex
// 9, a, b, c, d, e, f

//  0xa7;   // Easy to represent in binary
// a:1010 + 7:0111 = 10100111

// 0x0000b1c9   // 4 bytes
// 0000 0000 0000 0000 1011 0001 1100 1001

// 0xfffffff0
// 1111 1111 1111 1111 1111 1111 1111 0000

//      * * * SIGN MAGNITUDE * * *
// Decimal - Binary    Decimal - Binary
// 0 - 0000                 
// 1 - 0001                 -1 - 1001
// 2 - 0010                 -2 - 1010
// 3 - 0011                 -3 - 1011
// 4 - 0100                 -4 - 1100
// 5 - 0101                 -5 - 1101
// 6 - 0110                 -6 - 1110
// 7 - 0111                 -7 - 1111



// Unsigned numbers: smallest = 0, larget = 2^n - 1 (n == # bits)

// Binary adding:
// 3 + 5
// 0 0 1 1
//+0 1 0 1
//________
// 1 0 0 0

// 15 + 1
// 1 1 1 1
//+0 0 0 1

//1 0 0 0 0
//^ Carry bit overflow

//          * * * NEGATIVE NUMBERS * * *
// First bit is negative, also known as the 'most significant bit'
// Smallest: -(2^n-1 - 1)
// Largest: 2^n-1 -1

// 1) Two representations of 0.
// 2) Different rules for positive and negative values
// 3) Additions works normally with 'end-around carry'

// 0101     5 - 3
//+1100
//10001
//+0001
//=0010     = 2

// Ones complement - to get negative, invert all bits

// Two's complement - To get negative: 1) Invert all bits, 2) Add 1.

