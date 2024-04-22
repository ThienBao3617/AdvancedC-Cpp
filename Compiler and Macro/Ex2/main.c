#include <stdio.h>
#include "math_utils.h" // include header file

// Define the declared function in the header file
int add(int a, int b) {
    return a + b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Sum of %d and %d is: %d\n", a, b, add(a, b));
    return 0;
}