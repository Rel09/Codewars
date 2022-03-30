/*mplete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

Examples:

solution('abc', 'bc') // returns true
solution('abc', 'd') // returns false*/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool solution(const char *string, const char *ending){
  int x = strlen(string) - strlen(ending);
  int y = strlen(ending) + 1;
  
  char *s;
  s = (char*)malloc(y * sizeof(char*));
  
  int index = 0;
  for (int i = x; i < strlen(string); ++i){
    s[index] = string[i];
    index +=1;
  }
  s[index] = '\0';
  
  if (strcmp(s, ending) == 0){return true;}
  return false;
}