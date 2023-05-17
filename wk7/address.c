#include <stdio.h>

void foo() {
    int x = 42;
}

int main() {
    printf("%lx\n", (long) foo);
}