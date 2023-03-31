#include <stdio.h>

int y = 55;             // Global variable Y

void swap(int* x, int* y) {   // swap x and y using pointers
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int x = 42;         // Local variable X
    printf("x=%d\n", x);

    int* px = &x;       // px is a pointer to the address of x
    printf("px=%lx\n", (long) px);  // Pointers are 8 byte longs.

    *px = 77;           // Dereference where px is pointing to
    printf("x=%d\n", x);

    printf("Sizeof px=%ld\n", sizeof(px));

    int** ppx = &px;    // ppx is a pointer to a pointer to an int
    printf("**ppx=%d\n", **ppx); 

    **ppx = 13;
    printf("x=%d\n", x);

    // x == 13
    int y = 99;
    swap(&x, &y);

    printf("x=%d, y=%d\n", x, y);


    return 0;
}