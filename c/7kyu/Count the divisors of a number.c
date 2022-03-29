/*Count the number of divisors of a positive integer n.

Random tests go up to n = 500000.
Examples (input --> output)

4 --> 3 (1, 2, 4)
5 --> 2 (1, 5)
12 --> 6 (1, 2, 3, 4, 6, 12)
30 --> 8 (1, 2, 3, 5, 6, 10, 15, 30)*/

#include <stdio.h>

int divisors(int n) {
  int count = 0;
  for (int i = 1; i < n + 1; ++i){float x = (float)n / i;int y = (int) x;
    if ((float)y-x == 0.000000){count += 1;}
  }
return count;
}