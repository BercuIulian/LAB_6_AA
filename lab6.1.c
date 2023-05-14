#include <stdio.h>
#include <math.h>

double pi(int n) {
    double sum = 0.0;
    for (int k = 0; k < n; k++) {
        sum += (double)(4 / (8 * k + 1) - 2 / (8 * k + 4) - 1 / (8 * k + 5) - 1 / (8 * k + 6)) / pow(16, k);
    }
    return sum;
}

int main() {
    int n = 1000; // example Nth decimal digit of Pi
    double p = pi(n);
    int digit = (int)(p * pow(10, n - 1)) % 10;
    printf("The %dth decimal digit of Pi is %d.\n", n, digit);
    return 0;
}
