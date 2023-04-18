#include <stdio.h>
    
int foo(int * num) {
    register int i = num[5];
}


int main() {
    int hi = 5;
    int* yo = &hi;

    foo(yo);
    printf("%ls\n", yo);
}