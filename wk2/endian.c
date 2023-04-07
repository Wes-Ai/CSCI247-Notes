#include <stdio.h>

int main() {
    int x = 0xcafeface;
    unsigned char* p = (unsigned char*) &x;
    printf("%x\n", *p);
}