#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    printf("I am the parent\n");
    
    // Fork a child
    int pid = fork();
    if (pid == 0) {
        for (int i = 0; i < 1000000; i++) {
            printf("I am the child\n");
        }
    } else {
        for (int i = 0; i < 1000000; i++) {
            printf("I am still the parent\n");
        }
    }
    printf("Ending\n");
    return 0;
}
