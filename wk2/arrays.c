#include <stdio.h>

void printarray(int* a, int num) {   // a is the memory address where a begins
    for (int i = 0; i < num; i++) { // Divide by 4 bytes (int)
        printf("a[%d]=%d\n", i, a[i]);
    }
}

long unsigned int strlen(const char* s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        result++;
    }
    return result;
}

int main() {
    char* s = "Jonathon";     // array with a \0 at the end (null terminated)
    printf("length of s=%ld\n", strlen(s));
    printf("%s\n", s);
            
    int a[] = { 1, 2, 3, 4, 66, 77, 88 };   // 4 bytes * amount of elements
    printarray(a, sizeof(a) / sizeof(int)); // Pass sizeof to other functions
        // Only the main function knows that this is an array,
        // so we must pass in the size for other functions.

    return 0;
}
