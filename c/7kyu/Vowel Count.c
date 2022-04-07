/*Return the number (count) of vowels in the given string.

We will consider a, e, i, o, u as vowels for this Kata (but not y).

The input string will only consist of lower case letters and/or spaces.*/

#include <stddef.h>
#include <string.h>

size_t get_count(const char *s){
  char vowels[] = {'a','e','i','o','u'};
  int total = 0;
  
  for (int i = 0; i < strlen(s); ++i){
    for (int j = 0; j < strlen(vowels); ++j){
      if (s[i] == vowels[j]){
        total +=1;
      }
    }
  }
return total;  
}