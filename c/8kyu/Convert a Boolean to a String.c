/*Implement a function which convert the given boolean value into its string representation.

Note: Only valid inputs will be given. */


#include <stdbool.h>

const char *boolean_to_string(bool b){
  if (b == 1){return "true";}
  else {return "false";}
}