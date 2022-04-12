/*Given a sequence of numbers, find the largest pair sum in the sequence.

For example

[10, 14, 2, 23, 19] -->  42 (= 23 + 19)
[99, 2, 2, 23, 19]  --> 122 (= 99 + 23)*/


// -------------------SECOND VERSION----------------

#include <stddef.h>

long long largest_pair_sum (size_t length, const int numbers[length]){
  long upper_num[2] = {numbers[0], NULL};
  for (int i = 1; i < length; ++i){
    if (numbers[i] >= upper_num[0]){
      upper_num[1] = upper_num[0];
      upper_num[0] = numbers[i];   
    }
    else if (numbers[i] > upper_num[1]){
      upper_num[1] = numbers[i];
    }
  }
  
return upper_num[0] + upper_num[1];
}


// -------------------FIRST VERSION-----------------
#include <stddef.h>
#include <stdio.h>

long long largest_pair_sum (size_t length, const int numbers[length]){
  long first = (long)numbers[0];
  long second = (long)numbers[1];
  int count = 0;

  //Find the "First biggest Int"
  for (int i = 1; i < length; ++i){
    // >
    if ((long)numbers[i] > first){
      second = first;
      first = (long)numbers[i];
      count = 0;
    }
    // ==
    else if ((long)numbers[i] == first){count = 1;}
    
    //Check for the second numbers
    else if ((long)numbers[i] > second){second = (long)numbers[i];}
  }
  
  if (count == 1){return first + first;}
  
  return first + second;
}