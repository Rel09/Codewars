/*Find the number with the most digits.

If two numbers in the argument array have the same number of digits, return the first one in the array.*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int find_longest(int *numbers, size_t numbers_size){
  long num = (long) numbers[0];
  long y = fabsl((long) numbers[0]);
  int num_size = snprintf(NULL, 0, "%ld", y);
  
  for (int i = 0; i < numbers_size; ++i){
    //To Int to Sizeof(int)
    long x = fabsl((long) numbers[i]);
    int temp_size = snprintf(NULL, 0, "%ld", x);

    // If the Int is Longer
    if (num_size < temp_size){num = (long) numbers[i];num_size = temp_size;}
  }
  
  return num;
}