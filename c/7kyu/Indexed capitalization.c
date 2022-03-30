/*Given a string and an array of integers representing indices, capitalize all letters at the given indices.

For example:

    capitalize("abcdef",[1,2,5]) = "aBCdeF"
    capitalize("abcdef",[1,2,5,100]) = "aBCdeF". There is no index 100.

The input will be a lowercase string with no spaces and an array of digits.

Good luck!*/

#include <stdlib.h>
#include <string.h>

char *capitalize(const char *str_in, size_t z, size_t indices[z]) {
  char *s;
  int len = strlen(str_in) + 1;
  s = (char*)malloc(len * sizeof(char*));
  
   //Create new manipulable STR
  for(int i = 0;i < strlen(str_in);++i){
    s[i] = str_in[i];
  }
  s[len-1] = '\0';
  
  //Set the char Upper()
  for (int j = 0; j < z; ++j){
    if (indices[j] < strlen(s)){
      s[indices[j]] = toupper(s[indices[j]]);
    }
  }
  
return s;
}