/*Your task is to write function findSum.

Upto and including n, this function will return the sum of all multiples of 3 and 5.

For example:

findSum(5) should return 8 (3 + 5)

findSum(10) should return 33 (3 + 5 + 6 + 9 + 10)*/

int findSum (int n){
  int finalamount = 0;
  for (int i = n; i > 0; --i){
    float x = (float)i/3;
    float xx = (float)i/5;
    int y = (int)x;
    int yy = (int)xx;
    float totall = (float) yy - xx;
    float total = (float) y - x;
    if (total == 0.000000 || totall == 0.000000 ){finalamount += i;}
  }
return finalamount;
}
