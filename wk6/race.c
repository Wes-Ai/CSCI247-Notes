#include <time.h>
#include <stdio.h>
#include <math.h>

int main() {
    clock_t start, end;
    double cpu_time_used;
    int amt = 99999;

    start = clock();
    int a[amt], b[amt];
    for (int i = 0; i < amt; i++) {
        a[i] = 1;
        b[i] = 2;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time1: %f\n", cpu_time_used);

    clock_t start2, end2;
    double cpu_time_used2;

    start2 = clock();
    int c[amt], d[amt];
    for (int i = 0; i < amt; i++) {
        c[i] = 1;
    }
    for (int i = 0; i < amt; i++) {
        d[i] = 2;
    }
    end2 = clock();
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    printf("\n");
    printf("Time2: %f\n", cpu_time_used2);
}

    