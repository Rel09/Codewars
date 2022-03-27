/*Your task is to return the sum of Triangular Numbers up-to-and-including the nth Triangular Number.

Triangular Number: "any of the series of numbers (1, 3, 6, 10, 15, etc.) obtained by continued summation of the natural numbers 1, 2, 3, 4, 5, etc."

[01]
02 [03]
04 05 [06]
07 08 09 [10]
11 12 13 14 [15]
16 17 18 19 20 [21]

e.g. If 4 is given: 1 + 3 + 6 + 10 = 20.

Triangular Numbers cannot be negative so return 0 if a negative */

int sumTriangularNumbers(int n){
  int pyr_skip = 0;
  int pyr = 1;
  int total = 0;
  if (n > 0){
    for (int i = 0; i < n; ++i){
      for (int j = 0;j < pyr;++j){
        pyr_skip += 1;
      }
      total += pyr_skip;
      pyr += 1;
    }
    return total;
  }
  else{return 0;}
}