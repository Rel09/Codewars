/*Given a string, turn each character into its ASCII character code and join them together to create a number - let's call this number total1:

'ABC' --> 'A' = 65, 'B' = 66, 'C' = 67 --> 656667

Then replace any incidence of the number 7 with the number 1, and call this number 'total2':

total1 = 656667
              ^
total2 = 656661
              ^

Then return the difference between the sum of the digits in total1 and total2:

  (6 + 5 + 6 + 6 + 6 + 7)
- (6 + 5 + 6 + 6 + 6 + 1)
-------------------------
                       6*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int calc(const char *source){
  int total1 = 0;
  int total2 = 0;
  char *s;
  int len = strlen(source) *3 + 1;
  s = (char*)malloc(len * sizeof(char*));
  
  //Convert STR to ASCII str
  int index = 0;
  for (int i = 0; i < strlen(source); ++i){int x = (int) source[i];char y[4];sprintf(y, "%d", x);
    for (int j = 0; j < strlen(y); ++j){s[index] = y[j];index += 1;}
  }
  s[index] = '/0';

  //Calculate each Int in the Str
  for (int i = 0; i < strlen(s); ++i){
    //Str to Int
    char y = s[i];
    int x = atoi(&y);
    //If the Number is 7
    if (x == 7){total1 += 1;total2 += 7;}
    else {total1 += x;total2 += x;}
  }

return total2 - total1;
}