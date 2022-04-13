/*Find the number with the most digits.

If two numbers in the argument array have the same number of digits, return the first one in the array.*/

//Second method
#include <stddef.h>

int check_num(int n){
  //i believe this is faster than /10 methods
  if (n < 10) return 1;
  else if (n < 100) return 2;
  else if (n < 1000) return 3;
  else if (n < 10000) return 4;
  else if (n < 100000) return 5;
  else if (n < 1000000) return 6;
  else if (n < 10000000) return 7;
  else if (n < 100000000) return 8;
  else if (n < 1000000000) return 9;
  else if (n < 10000000000) return 10;
  else if (n < 100000000000) return 11;
}

int find_longest(int *numbers, size_t numbers_size){
  int index[2] = {0};
  int temp;
  
  for (int i = 0; i < numbers_size; ++i){
    temp = numbers[i];
    //Handle Negative Numbers
    if (temp < 0){temp *= -1;}
    //Actual Checkup
    if (check_num(temp) > index[0]){
      index[0] = check_num(temp);
      index[1] = i;
    }

  }
return numbers[index[1]];
}

//First method
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