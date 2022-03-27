/*This time no story, no theory. The examples below show you how to write function accum:
Examples:

accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"

The parameter of accum is a string which includes only letters from a..z and A..Z.*/

#include <stdio.h>
#include <string.h>

char *accum(const char *source){
  int array_size = 0;
  
  // Get the new STR size
  for (int i = 0; i < strlen(source); ++i){array_size = array_size + i + 2;}
  
  //Allocate the new array
  char *s;
  s = (char *)malloc(array_size * sizeof(char));
  int array_siz = 1;
  int value = 0;
  
  for (int i = 0; i < strlen(source); ++i){
    for (int j = 0; j < array_siz; ++j){
      //If its the first Char, Capital
      if (j == 0){s[value] = toupper(source[i]);value += 1;}
      //Else, Lower char
      else{s[value] = tolower(source[i]);value += 1;}
    }
    //Do not add - if its the last char
    if  (i != strlen(source) - 1){s[value] = '-';value += 1;}
    array_siz += 1;
  }
  
s[value] = '\0';
return s;
}