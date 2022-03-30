/*I will give you an integer. Give me back a shape that is as long and wide as the integer. The integer will be a whole number between 1 and 50.
Example

n = 3, so I expect a 3x3 square back just like below as a string:

+++
+++
+++                                                                */

#include <stdlib.h>
#include <stddef.h>
#include <string.h> 
#include <stdio.h>

char* generate_shape(size_t n) {
  // Define the char length
  int num = n;
  int size_char = (num + 1) * num;
  
  // New STR
  char *s;
  s = (char*)calloc(size_char, sizeof(char*));

  char x = '+';
  int index = 0;
  while (strlen(s) < size_char){
    
    //Add each  "" + ""
    for (int i = 0; i < num ; ++i){
      s[index] = x;
      index += 1;
    }
    
   //else, New line
    if (strlen(s) < size_char){
      s[index] = '\n';
      index += 1;
    }
  }
  
  s[index - 1] = '\0';
  return s; 
}
