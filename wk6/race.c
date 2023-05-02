#include <time.h>
#include <stdio.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    for (int i = 0; i < 15; i++) {
        printf("foo");
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time1: %f\n", cpu_time_used);

    clock_t start2, end2;
    double cpu_time_used2;

    start2 = clock();
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    printf("foo");
    end2 = clock();
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time2: %f\n", cpu_time_used2);
}

    