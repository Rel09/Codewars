/*Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.
Examples:

Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321*/

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

uint64_t descendingOrder(uint64_t n){
  //Find the Length of Int
  unsigned long long number = n;
  int len = 1;
  while (number >= 10){number = number / 10;len +=1;}

  // If the INT only has 1 character or less
  if (len <= 1){return (int)n;}
  
  //Convert Int to STR
  char s[len + 1];
  sprintf(s, "%ld", n);

  //Switch position loop
  char temp_char;
  for (int i = 0; i < len; ++i){
    for (int j = i + 1; j < len; ++j){
      if (s[i] < s[j] && isdigit(s[i])){temp_char = s[i];s[i] = s[j];s[j] = temp_char;}
    }
  }
  
  //Convert STR to INT
  s[len] = '\0';
  number = strtoul(s, NULL, 10);
  return number;
}