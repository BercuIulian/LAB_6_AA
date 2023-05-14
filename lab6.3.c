#include <stdio.h>
#include <math.h>

int main() {
   int n = 1000; // replace 1000 with the desired Nth digit
   double a = 1.0, b = 1.0/sqrt(2.0), t = 1.0/4.0, p = 1.0;
   double pi_old = 0.0, pi_new = 0.0;
   for (int i = 0; i < n; i++) {
      pi_old = pi_new;
      double a_old = a;
      a = (a_old + b) / 2.0;
      b = sqrt(a_old * b);
      t = t - p * pow(a_old - a, 2);
      p = 2.0 * p;
      pi_new = pow(a + b, 2) / (4.0 * t);
      if (pi_new == pi_old) {
         break;
      }
   }
   printf("The %dth digit of pi is %d\n", n, (int)(pi_new * 10));
   return 0;
}
