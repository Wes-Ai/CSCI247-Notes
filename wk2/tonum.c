#include <stdio.h>

int atoi(const char* s) {
    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {    // \0 == 0000000000
        int cvalue = s[i] - '0';            // 0 == 0
        result = result * 10 + cvalue;  // Multiply by 10 to add up ints
    }
    return result;
}

// Convert n to the string and put result in buf
void itoa(int n, char* buf) {

}

// 3692 / 10 == 2
// 369 / 10 == 9
// 36 / 10 == 6
// 3 / 10 == 3

// Gives you the string but in reverse order.

int main() {
    char s[10];
    scanf("%s", s);

    printf("You entered %s\n", s);

    int num = atoi(s);      // Convert sring s to int
    printf("the number is %d\n", num);
}