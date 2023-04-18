#include <stdio.h>
#include <unistd.h>

char* message = "Hello World\n";

int main() {
    int i = 10;         // move $10 to %r8

top:
    if (i == 0) {
        goto bottom;
    }
        write(1, message, 12);

        i--;            // dec %r8
        goto top;
bottom:

    return 0;
}
