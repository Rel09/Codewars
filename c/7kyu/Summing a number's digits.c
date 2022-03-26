/*Write a function named sumDigits which takes a number as input and returns the sum of the absolute value of each of the number's decimal digits.

For example: (Input --> Output)

10 --> 1
99 --> 18
-32 --> 5

Let's assume that all numbers in the input will be integer values.*/

int sum_digits(int n) {
  if (n==0){return 0;}
  char c[4];
  int total = 0;
  sprintf(c, "%i", n);
  for (int i = 0;i < strlen(c);++i){
    char x = c[i];
    if (isdigit(x)){
      int y = atoi(&x);
      total += y;
    }
  }
  return total;
}