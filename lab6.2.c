#include <stdio.h>
#include <math.h>

double agm(double a, double b, int n) {
    if (n == 0) {
        return (a + b) / 2;
    } else {
        double agm1 = agm(a, sqrt(a * b), n - 1);
        double agm2 = agm(sqrt(a * b), b, n - 1);
        return (agm1 + agm2) / 2;
    }
}

double pi(int n) {
    double a = 1.0;
    double b = 1.0 / sqrt(2);
    double t = 1.0 / 4.0;
    double p = 1.0;
    for (int k = 0; k < n; k++) {
        double a1 = (a + b) / 2;
        double b1 = sqrt(a * b);
        double t1 = t - p * pow(a - a1, 2);
        double p1 = 2 * p;
        a = a1;
        b = b1;
        t = t1;
        p = p1;
    }
    double pi = pow(a + b, 2) / (4 * t);
    return pi;
}

int main() {
    int n = 1000; // example Nth decimal digit of Pi
    double p = pi(n);
    int digit = (int)(p * pow(10, n - 1)) % 10;
    printf("The %dth decimal digit of Pi is %d.\n", n, digit);
    return 0;
}

