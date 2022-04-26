/*Take 2 strings s1 and s2 including only letters from ato z. Return a new sorted string, the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.
Examples:

a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
longest(a, b) -> "abcdefklmopqwxy"

a = "abcdefghijklmnopqrstuvwxyz"
longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"*/

#include <stdlib.h>
#include <string.h>

char *longest (const char *s1, const char *s2){
  //Variable needed to get the end result
  int count[26] = {0};int len = 0;
  
  //Copying both string into a new one (we want one loop for both string)
  char *s;s = (char*)malloc(strlen(s1) + strlen(s2) * sizeof(char*));
  strcat(s, s1);strcat(s, s2);
  
  //Counting the chars
	for (int i = 0; i < strlen(s); ++i){if (count[s[i] - 97] == 0){count[s[i] - 97]++;len++;}}
  
  //Preparing final returning string
  char *st;st = (char*)malloc(len * sizeof(char));
  int index = 0;
  
  //Adding letter to the string
  for (int i = 0; i < 26; ++i){if (count[i] > 0){st[index] = (char) i + 97;index++;}}
  st[index] = '\0';
  
free(s);  
return st;
}