/*Create a function that returns the sum of the two lowest positive numbers given an array of minimum 4 positive integers. No floats or non-positive integers will be passed.

For example, when an array is passed like [19, 5, 42, 2, 77], the output should be 7.

[10, 343445353, 3453445, 3453545353453] should return 3453455.*/

#include <stddef.h>
long sum_two_smallest_numbers(size_t n, const int numbers[n]) {
  int num1[] = {numbers[0], 0};
  int num2 = -1;
  
  for (int i = 1; i < n; ++i){
    if (numbers[i] < num1[0]){num1[0] = numbers[i];num1[1] = i;}
    if (numbers[i] > num2){num2=numbers[i];}
  }
  
  for (int i = 0; i < n; ++i){
    if (numbers[i] < num2 && i != num1[1]){num2 = numbers[i];}
  }
  
  return (long) num1[0] + num2;
}