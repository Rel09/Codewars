/*Story

The Pied Piper has been enlisted to play his magical tune and coax all the rats out of town.

But some of the rats are deaf and are going the wrong way!
Kata Task

How many deaf rats are there?
Legend

    P = The Pied Piper
    O~ = Rat going left
    ~O = Rat going right

Example

    ex1 ~O~O~O~O P has 0 deaf rats

    ex2 P O~ O~ ~O O~ has 1 deaf rat

    ex3 ~O~O~O~OP~O~OO~ has 2 deaf rats */

#include <string.h>


int countDeafRats(const char *town){
  int Switch = 0;
  int lowiq_fish = 0;
  
  for (int i = 0; i < strlen(town); ++i){
    char x = town[i];
    
    // If the char is ~
    if (x == '~'){ 
      if (town[i + 1]  == 'O'){
        // If theres a bad fish
        if (Switch == 1){lowiq_fish += 1;}
        i += 1;
      }
      
    }
    // If the char is 0
    else if (x == 'O'){
      if (town[i + 1]  == '~'){
        // If theres a bad fish 
        if (Switch == 0){lowiq_fish += 1;}
        i += 1;
      }
    }
    
    // If the Char is ' ' , Skip
    else if (x == ' '){continue;}
    // If the Char is P, Switch = 1
    else if (x == 'P'){Switch = 1;}
  }
    
    return lowiq_fish;
}