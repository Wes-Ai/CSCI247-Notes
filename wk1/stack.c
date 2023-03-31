#include <stdio.h>

int* foo() {    // foo returns a pointer to an int
    int a = 42;
    int* pa = &a;
    return pa;
}

void bar() {
    char b = 1;
    char* pb = &b;   // Line stops compiler from optimizing away
}

int main() {
    int* px = foo();
    printf("*px=%d\n", *px);

    bar();
    printf("*px=%x\n", *px);
    
    return 0;
}