/*Your function takes two arguments:

    current father's age (years)
    current age of his son (years)

Сalculate how many years ago the father was twice as old as his son (or in how many years he will be twice as old).*/

int twice_as_old (int father_age, int son_age)
{
  int x = son_age*2;
  printf("%i\n", x);
  if (father_age > x){
    return father_age - x;
  }
  else{
    return x - father_age;
  }
}
