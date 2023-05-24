#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("I am your father, Luke\n");

    // Create a child
    int pid = fork();
    printf("PID=%d\n", pid);
    if (pid == 0) {
        // Child        
        printf("Aghhhh\n");
        execl("./filesize", "./filesize", "filesize.c", NULL);
        printf("Never get here...\n");

    } else {
        // Parent
        printf("come to the Dark Side\n");
    }

    // Everyone ends the same way
    printf("Force Ghost\n");
}
