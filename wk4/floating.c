#include <stdio.h>

int main() {
    float sum = 0;
    for (int i = 0; i < 1000000000; i++) {
        sum++;
    }
    printf("%f\n", sum);
}