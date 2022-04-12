/*A pangram is a sentence that contains every single letter of the alphabet at least once. For example, the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters A-Z at least once (case is irrelevant).

Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation.*/


#include <stdbool.h>
#include <string.h>

bool is_pangram(const char *str_in) {
  int hash[26] = {0};
  int total = 0;
  char x;
  
  for (int i = 0; i < strlen(str_in); ++i){
    x = tolower(str_in[i]);
    if (x - 'a' >= 0 && str_in[i] - 'a' < 26 && hash[x - 'a'] == 0){
      hash[x - 'a']++;
    }
  }
  
  // Add up the total
  for (int i = 0; i < 26; ++i){total += hash[i];}
  if (total == 26){return true;}
  return false;
}