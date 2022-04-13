/*Write a function that takes a string of parentheses, and determines if the order of the parentheses is valid. The function should return true if the string is valid, and false if it's invalid.
Examples

"()"              =>  true
")(()))"          =>  false
"("               =>  false
"(())((()())())"  =>  true

Constraints

0 <= input.length <= 100

Along with opening (() and closing ()) parenthesis, input may contain any valid ASCII characters. Furthermore, the input string may be empty and/or not contain any parentheses at all. Do not treat other forms of brackets as parentheses (e.g. [], {}, <>).*/

//I couldve done much better / not use malloc, but since im learning, i just wanted to use it for fun
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool validParentheses(const char *str_in) {
  printf("_______________\n");
  //Prepare a new string
  char *s;
  s = (char*)malloc((int)strlen(str_in) * sizeof(char*));
  
  //Count all parenthesis & add all parenthesis in the new string
  int count = 0;int index = 0;
  for (int i = 0; i < (int)strlen(str_in); ++i){
    if ((int)str_in[i] == 40 || (int)str_in[i] == 41){
      s[index] = str_in[i];
      index +=1;
      count +=1;
    }}
  s[index] = '\0';
  
  // Handle the basic exceptions
  if (count == 0){
    printf("Returning True\n");
    return true;}
  else if (count == 1){
    return false;
    printf("Returning False\n");
  }
  
  printf("New String: %s\n", s);
  //Actual loop
  int parentheses = 0;
  
  for (int i = 0; i < count; ++i){
    if ((int)s[i] == 40){
      parentheses +=1;
    }
    else if ((int)s[i] == 41){
      parentheses -=1;
    }
    
    if (parentheses < 0){
      printf("Returning False x\n");
      return false;}
    
  }
  if (parentheses != 0){return false;}
printf("Returning True x   Parentheses: %i\n", parentheses);
return true;
}