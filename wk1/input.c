#include <stdio.h>

int main() {
    printf("Enter a number: ");
    int num;
    scanf("%d", &num);      // Pass the address of num,
                            // so it can change it correctly

    printf("You entered %d\n", num);
}