#include <stdio.h>

int main() {
    char s[50];
    scanf("%s", s);
    printf("You entered %s\n", s);

    char* t = s;
    printf("t=%s\n", t);

    t[0] = 'W';     // t points to the same place as s, changes s also
    printf("t=%s\n", t);
    printf("s=%s\n", s);

    int x = 0xa3;   // Hexadecimal number a3
}
