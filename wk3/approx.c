#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool is_equal(float a, float b, float delta) {
    float diff = fabs(a - b);
    // Ternary operator
    return diff <= delta ? true : false;
}

int main() {

    float a = sqrt(2);
    // if (a * a == 2) {
    if(is_equal(a*a, 2, 0.0001)) {
        printf("Equal\n");
    }
    else {
        printf("What the heck %f\n", a * a);
    }

    return 0;
}