/*Task

Given a string str, reverse it omitting all non-alphabetic characters.
Example

For str = "krishan", the output should be "nahsirk".

For str = "ultr53o?n", the output should be "nortlu".
Input/Output

    [input] string str

A string consists of lowercase latin letters, digits and symbols.

    [output] a string*/

char *reverse_letter(const char *str){
  int str_len;
  
  //Count all char in the string
  for (int i = strlen(str); i != 0; --i){if (isalpha(str[i]) > 0){str_len += 1;}}

  // Prepare the new string
  char *s;
  s = (char*)malloc(str_len + 1 * sizeof(char));

  //Put the reversed char in the new string
  int str_i = 0;
  for (int i = strlen(str) ; i >= 0; --i){
    if (isalpha(str[i]) > 0){s[str_i] = str[i];str_i += 1;}
  }

s[str_i] = '\0';
return s;
}