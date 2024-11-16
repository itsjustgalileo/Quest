#include "./quest_internal.h"

int quest_calculate_gcd(int a, int b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int quest_factorial(int n) {
    int i, result = 1;
    for (i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
