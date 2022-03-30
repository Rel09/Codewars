/**nput >> Output Examples

tidyNumber (12) ==> return (true)

Explanation:

The number's digits { 1 , 2 } are in non-Decreasing Order (i.e) 1 <= 2 .

tidyNumber (32) ==> return (false)

Explanation:

The Number's Digits { 3, 2} are not in non-Decreasing Order (i.e) 3 > 2 .*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool tidyNumber(int number){
  //Get the Len of the number
  int size;
  if      (number >= 1000000000) size = 10;
  else if (number >= 100000000)  size = 9;
  else if (number >= 10000000)   size = 8;
  else if (number >= 1000000)    size = 7;
  else if (number >= 100000)     size = 6;
  else if (number >= 10000)      size = 5;
  else if (number >= 1000)       size = 4;
  else if (number >= 100)        size = 3;
  else if (number >= 10)         size = 2;
  else size=1;
  
  //Store the new STR
  char *s;
  s = (char*)malloc(size * sizeof(char*));
  sprintf(s, "%d", number);
  
  int num;
  for (int i = 0; i < size; ++i){
    //Char to Int
    char x = s[i];
    int y = atoi(&x);
    // Check if char is < than the previous one
    if (i == 0){num = y;}
    else{if (y < num){return false;}
      num = y;
    }
  }
  return true;
}
  