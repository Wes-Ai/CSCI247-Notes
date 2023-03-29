#include <stdio.h>

// Forward declaration of function
// dread_pirate is void and takes no arguments
void dread_pirate(void);
float f2c(int);

int main() {
    printf("There is dead, and mostly dead.\n");
    dread_pirate();

    // Types in C
    int answer = 42;
    float pi = 3.1415926535;
    printf("Answer=%d, pi=%f\n", answer, pi);
    char c = 'w';   // Single quotes for characters
    long bignum = 123456789;

    // Size of each type
    printf("Ints are %ld bytes\n", sizeof(int));    // 32 bits
    printf("Chars are %ld bytes\n", sizeof(c));     // 8 bits
    printf("Floats are %ld bytes\n", sizeof(float));// 32 bits
    printf("Longs are %ld bytes\n", sizeof(bignum));// 64 bits


    // Loop
    // for(initializer; condition; increment)
    for (int i = 0; i < 10; i++)
    {
        printf("%d Fahrenheit = %f Celsius\n", i, f2c(i));
    }
    
    // Array of int
    int a[] = { 1, 2, 3, 4, 77 };
    printf("Sizeof array a=%ld\n", sizeof(a));

    // Return success.
    return 0;
}

// Implementation
void dread_pirate() {
    printf("Wesley\n");
}

float f2c(int f) {
    return 5.0/9.0 * (f - 32);
}
