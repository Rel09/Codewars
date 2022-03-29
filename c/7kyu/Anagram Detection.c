/*An anagram is the result of rearranging the letters of a word to produce a new word (see wikipedia).

Note: anagrams are case insensitive

Complete the function to return true if the two arguments given are anagrams of each other; return false otherwise.
Examples

    "foefet" is an anagram of "toffee"

    "Buckethead" is an anagram of "DeathCubeK"*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int is_anagram(const char *test, const char *original){
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  
  //Create new Int array, to +1 each letter
  int *array;
  array = calloc(strlen(alphabet), sizeof(int));
  
  //Count all the char
  for (int i = 0; i < strlen(test);++i){
    for (int j = 0; j < strlen(alphabet);++j){
      if (tolower(test[i]) == alphabet[j]){array[j] += 1;}
    }
  }
    
  // Check the wanted word, if all the char are there
    for (int i = 0; i < strlen(original);++i){
      for (int j = 0; j < strlen(alphabet);++j){
        if (tolower(original[i]) == alphabet[j]){
          if (array[j] > 0){array[j] -= 1;continue;}
          else {return 0;}
        }
       }
      }
  
  // Scan the remaining of the int array
  for (int i = 0; i < strlen(alphabet);++i){if (array[i] > 0){return 0;}}
  
  return 1;
}