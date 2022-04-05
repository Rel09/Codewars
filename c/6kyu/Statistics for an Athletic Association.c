/*You are the "computer expert" of a local Athletic Association (C.A.A.). Many teams of runners come to compete. Each time you get a string of all race results of every team who has run. For example here is a string showing the individual results of a team of 5 runners:

"01|15|59, 1|47|6, 01|17|20, 1|32|34, 2|3|17"

Each part of the string is of the form: h|m|s where h, m, s (h for hour, m for minutes, s for seconds) are positive or null integer (represented as strings) with one or two digits. Substrings in the input string are separated by , or ,.

To compare the results of the teams you are asked for giving three statistics; range, average and median.

    Range : difference between the lowest and highest values. In {4, 6, 9, 3, 7} the lowest value is 3, and the highest is 9, so the range is 9 − 3 = 6.

    Mean or Average : To calculate mean, add together all of the numbers in a set and then divide the sum by the total count of numbers.

    Median : In statistics, the median is the number separating the higher half of a data sample from the lower half. The median of a finite list of numbers can be found by arranging all the observations from lowest value to highest value and picking the middle one (e.g., the median of {3, 3, 5, 9, 11} is 5) when there is an odd number of observations. If there is an even number of observations, then there is no single middle value; the median is then defined to be the mean of the two middle values (the median of {3, 5, 6, 9} is (5 + 6) / 2 = 5.5).

Your task is to return a string giving these 3 values. For the example given above, the string result will be

"Range: 00|47|18 Average: 01|35|15 Median: 01|32|34"

of the form: "Range: hh|mm|ss Average: hh|mm|ss Median: hh|mm|ss"`

where hh, mm, ss are integers (represented by strings) with each 2 digits.
Remarks:

    if a result in seconds is ab.xy... it will be given truncated as ab.
    if the given string is "" you will return "" */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* stat(char* strg) {
  //--Detect of how 'Players' we have
  int count = 1;for (int i = 0; i < strlen(strg); ++i){if (strg[i] == ','|| strg[i] == '.'){count += 1;}}
  //--Create a int for each of them
  int s[count];
  
  // All the variable for conversion
  int index = 0;
  int hours = 0;
  int minutes = 0;
  int seconds = 0;
  char h[3];
  char m[3];
  char sec[3];

  //--Calculate the stats of each Player in S[i]
  for (int i = 0; i < strlen(strg); ++i){
    // If char is ' '
    if (strg[i] == ' '){continue;}
    // If char is a separator, index +=1
    else if (strg[i] == ','|| strg[i] == '.'){index +=1;}
    //Get the 8 char for each player
    else {
      //Grab all the numbers
      h[0] = strg[i];
      h[1] = strg[i + 1];
      m[0] = strg[i + 3];
      m[1] = strg[i + 4];
      sec[0] = strg[i + 6];
      sec[1] = strg[i + 7];
      i += 7;
      //Convert Str to Int
      hours = atoi(h);
      minutes = atoi(m);
      seconds = atoi(sec);
      //Convert Hours > Minutes > Seconds
      seconds = seconds + (3600 * hours);
      seconds = seconds + (60 * minutes); ;
      s[index] = seconds;    
    }
  }
  //RANGE
  //Find the Smallest and Biggest number to compare
  int smallest = s[0];int biggest = 0;
  for (int i = 0; i < count ; ++i){if (smallest > s[i]){smallest =  s[i];}else if (biggest < s[i]){biggest = s[i];}}
  biggest = biggest - smallest;
  // Formating to Hours/Min/Sec
  int range_hours = 0;int range_minutes = 0;int range_seconds = 0;
  while (biggest >= 3600){range_hours +=1;biggest -= 3600;}
  while (biggest >= 60){range_minutes +=1;biggest -= 60;}
  range_seconds = biggest;
  printf("RANGE:   %i|%i|%i\n", range_hours, range_minutes,range_seconds);

  //Average - Average of all sum
  int total = 0;for (int i = 0; i < count; ++i){total += s[i];}
  total = total / count;
  // Formating to Hours/Min/Sec
  int average_hours = 0;int average_minutes = 0;int average_seconds = 0;
  while (total >= 3600){average_hours +=1;total -= 3600;}
  while (total >= 60){average_minutes +=1;total -= 60;}
  average_seconds = total;
  printf("AVERAGE: %i|%i|%i\n", average_hours,average_minutes,average_seconds);
  
  //Median -
  //Sort the list
  int temp;
  for(int i = 0; i < count; ++i){
    for (int j = i + 1; j < count; ++j){if (s[i] > s[j]){temp = s[i];s[i] = s[j];s[j] = temp;}}
  }
  
  //Check if the array len is odd
  int odd;if (count%2 == 0){odd = 1;}else {odd = 0;}
  
  int median;
  if (odd){median = (s[(count/2)-1] + s[(count/2)])/2;}
  else{double med = (float)count/2;int mad = count/2;if (med - mad > 0){mad+=1;}median = s[mad - 1];}
  
  // Formating to Hours/Min/Sec
  int median_hours = 0;int median_minutes = 0;int median_seconds = 0;
  while (median >= 3600){median_hours +=1;median -= 3600;}
  while (median >= 60){median_minutes +=1;median -= 60;}
  median_seconds = median;
  printf("MEDIAN:  %i|%i|%i\n\n", median_hours,median_minutes,median_seconds);
  
  //Return the string
  char *strr;
  strr = (char*)malloc(51*sizeof(char*));
  
  sprintf(strr, "Range: %02i|%02i|%02i Average: %02i|%02i|%02i Median: %02i|%02i|%02i",range_hours,range_minutes,range_seconds,
                                                                average_hours,average_minutes,average_seconds,
                                                                median_hours,median_minutes,median_seconds);

    printf("%s\n\n", strr);
  
  return strr;
}