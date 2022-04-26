/*Note: Numbers can be from 1 to 9. So 1 will be the first word (not 0).

If the input string is empty, return an empty string. The words in the input String will only contain valid consecutive numbers.
Examples

"is2 Thi1s T4est 3a"  -->  "Thi1s is2 3a T4est"
"4of Fo1r pe6ople g3ood th5e the2"  -->  "Fo1r the2 g3ood 4of th5e pe6ople"
""  -->  "" */


#include <string.h>
#include <ctype.h>

char *order_words (char *ordered, const char *words){
  int num = 0;
  int index = 0;

  for (int i = 0; i < strlen(words); ++i){
    if (num == words[i] - 49){ // Find all the numbers
      
      while (words[i] != 32 && i != 0){i--;} // Bring the index at the end of words

      if (words[i] == 32){i++;} //Make sure the first char is not ' '
      
      while (words[i] != 32 && i != strlen(words)){ //Add each char to Ordered[]
        ordered[index] = words[i];
        index++;
        i++;
      }
      //Space between word & loop back the entire string to find the next word
      ordered[index] = ' ';
      index++;
      num++;
      i = -1;
    }
  }
  
	ordered[index -1] = '\0';
	return ordered;
}