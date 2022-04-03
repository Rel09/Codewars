/*Some new cashiers started to work at your restaurant.

They are good at taking orders, but they don't know how to capitalize words, or use a space bar!

All the orders they create look something like this:

"milkshakepizzachickenfriescokeburgerpizzasandwichmilkshakepizza"

The kitchen staff are threatening to quit, because of how difficult it is to read the orders.

Their preference is to get the orders as a nice clean string with spaces and capitals like so:

"Burger Fries Chicken Pizza Pizza Pizza Sandwich Milkshake Milkshake Coke"

The kitchen staff expect the items to be in the same order as they appear in the menu.

The menu items are fairly simple, there is no overlap in the names of the items:

1. Burger
2. Fries
3. Chicken
4. Pizza
5. Sandwich
6. Onionrings
7. Milkshake
8. Coke */

char *get_order(const char *input) {
  //Storing the reccurence of word in Num int array
  char *num;
  num = (int*)calloc(8, sizeof(int*));
    
  int len;
  char *menu[8];
  menu[0] = "Burger";
  menu[1] = "Fries";
  menu[2] = "Chicken";
  menu[3] = "Pizza";
  menu[4] = "Sandwich";
  menu[5] = "Onionrings";
  menu[6] = "Milkshake"; 
  menu[7] = "Coke";

  //Parsing word using only the first two char
  for (int i = 0; i < strlen(input); ++i){
    char x = input[i];
    char x_two = input[i+1];
    
    // Check all the 8 items on the menu one per one
    for (int j = 0; j < 8; ++j){
      char y = tolower(menu[j][0]);
      char y_two = menu[j][1];
    
      // If the first two char are the same, Items are detected, +1 to their num
      if (x == y && x_two == y_two){
        //Skipping to the end of the word
        len = strlen(menu[j]) - 1;
        i += len;
        num[j] += 1;
      }
    }
    
  }
  // We need to get the String Length of the produced string for Malloc
  int total;
  for (int i = 0; i < 8; ++i){int y = strlen(menu[i]);total += ( (y + 1) * num[i]);}
  total += 1;

  char *s;
  s = (char*)malloc(total * sizeof(char*));
  
  // for each Num
  int index = 0;
  for (int i = 0; i < 8; ++i){
    
    // for each Number in Num[i]
    for (int j = 0; j < num[i]; ++j){
      
      //For each letter in Menu[i]
      len = strlen(menu[i]);
      for (int n = 0; n < len; ++n){
        s[index] = menu[i][n];
        index +=1;
      }
      // Space after each word
      s[index] = ' ';
      index += 1;
    }
  }
  
s[index-1] = '\0'; 
return s;
}