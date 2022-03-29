/*In this Kata, you will be given a string that may have mixed uppercase and lowercase letters and your task is to convert that string to either lowercase only or uppercase only based on:

    make as few changes as possible.
    if the string contains equal number of uppercase and lowercase letters, convert the string to lowercase.

For example:

solve("coDe") = "code". Lowercase characters > uppercase. Change only the "D" to lowercase.
solve("CODe") = "CODE". Uppercase characters > lowecase. Change only the "e" to uppercase.
solve("coDE") = "code". Upper == lowercase. Change all to lowercase.

More examples in test cases. Good luck!

Please also try:

Simple time difference

Simple remove duplicates*/



#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *solve(const char *str) {
  int upper = 0;
  int lower = 0;
  // Prepare new string
  char *s;
  s = (char *)malloc((strlen(str) + 1) * sizeof(char));

  //Scan all Chars
  for(int i = 0; i < strlen(str); ++i){ 
    int num = islower(str[i]);
    if (num > 0){lower +=1;}
    else {upper += 1;}
  }
  
  //Put back all the char in new STR
  for (int i = 0; i < strlen(str); ++i){
    if (lower >= upper){s[i] = tolower(str[i]);}
    else {s[i] = toupper(str[i]);}
  }

  //STR end
  s[strlen(str)] = '\0';
  
return s;
}