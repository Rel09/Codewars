/*There was a test in your class and you passed it. Congratulations!
#But you're an ambitious person. You want to know if you're better than the average student in your class.

You receive an array with your peers' test scores. Now calculate the average and compare your score!

Return True if you're better, else False!*/

#include <stdio.h>

int better_than_average(int class_points[], int class_size, int your_points) {
  int total = 0;
  for (int i = 0; i < class_size; ++i){
    total = total + class_points[i]; 
  }
  total = total / class_size;  
  
  if (total < your_points){
    return 1;
  }
  else {
    return 0;
  }
}