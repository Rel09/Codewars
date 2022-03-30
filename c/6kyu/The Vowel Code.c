/*Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:

a -> 1
e -> 2
i -> 3
o -> 4
u -> 5

For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.

Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.

For example, decode("h3 th2r2") would return "hi there".

For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels.*/

#include <stdlib.h>
#include <stdio.h>

char *encode(const char *string) {
  char alpha[] = "aeiou";
  char numbers[] = "12345";
  
  //Prepare the new STR
  char *s;
  s = (char*)malloc(strlen(string) * sizeof(char*));
  
  for (int i = 0; i < strlen(string); ++i){
    s[i] = string[i];
    for (int j = 0; j < strlen(alpha); ++j){
      // If char need to be encoded/decoded
      if (s[i] == alpha[j]){s[i] = numbers[j];}
    }
  }
  s[strlen(string)] = '\0';
  return s;
}

char *decode(const char *string) {
  // i just reversed both string name for Decode
  char numbers[] = "aeiou";
  char alpha[] = "12345";
  
  //Prepare the new STR
  char *s;
  s = (char*)malloc(strlen(string) * sizeof(char*));
  
  for (int i = 0; i < strlen(string); ++i){
    s[i] = string[i];
    for (int j = 0; j < strlen(alpha); ++j){
      // If char need to be encoded/decoded
      if (s[i] == alpha[j]){s[i] = numbers[j];}
    }
  }
  s[strlen(string)] = '\0';
  return s;
}