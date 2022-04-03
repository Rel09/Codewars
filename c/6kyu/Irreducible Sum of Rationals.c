/*You will have a list of rationals in the form

lst = [ [numer_1, denom_1] , ... , [numer_n, denom_n] ]

or

lst = [ (numer_1, denom_1) , ... , (numer_n, denom_n) ]

where all numbers are positive integers. You have to produce their sum N / D in an irreducible form: this means that N and D have only 1 as a common divisor.

Return the result in the form:

    [N, D] in Ruby, Crystal, Python, Clojure, JS, CS, PHP, Julia, Pascal
    Just "N D" in Haskell, PureScript
    "[N, D]" in Java, CSharp, TS, Scala, PowerShell, Kotlin
    "N/D" in Go, Nim
    {N, D} in C, C++, Elixir, Lua
    Some((N, D)) in Rust
    Some "N D" in F#, Ocaml
    c(N, D) in R
    (N, D) in Swift
    '(N D) in Racket

If the result is an integer (D evenly divides N) return:

    an integer in Ruby, Crystal, Elixir, Clojure, Python, JS, CS, PHP, R, Julia
    Just "n" (Haskell, PureScript)
    "n" Java, CSharp, TS, Scala, PowerShell, Go, Nim, Kotlin
    {n, 1} in C, C++, Lua
    Some((n, 1)) in Rust
    Some "n" in F#, Ocaml,
    (n, 1) in Swift
    n in Racket
    (n, 1) in Swift, Pascal, Perl

If the input list is empty, return

    nil/None/null/Nothing
    {0, 1} in C, C++, Lua
    "0" in Scala, PowerShell, Go, Nim
    O in Racket
    "" in Kotlin
    [0, 1] in C++, "[0, 1]" in Pascal
    [0, 1] in Perl

Example:

[ [1, 2], [1, 3], [1, 4] ]  -->  [13, 12]
1/2  +  1/3  +  1/4     =      13/12 */

#include <stdio.h>
#include <stdlib.h>

int* sumFracts(int lst[][2], int row) {
  //If theres nothing in the array, return {0,1}
  if (row <= 0){
    int *result;
    result = (int*)malloc(2*sizeof(int*));
    result[0] = 0;
    result[1] = 1; 
    return result;
  }
  
  //We keep the first fraction
  int total[2];
  total[0] = lst[0][0];
  total[1] = lst[0][1];
  
  int temp;
  for (int i = 1; i < row; i++){
    // Multiply both fractions by denominators, and add them together
    int x = lst[i][1]; 
    int y = total[1];
    total[0] = total[0] * x; 
    total[1] = total[1] * x;                         
    temp = lst[i][0] * y;
    total[0] = total[0] + temp;
  }
  
  // Find the greatest common denominator of both numbers
  int gcd;
  for(int i = 1; i <= total[0] && i <= total[1]; ++i){if(total[0]%i==0 && total[1]%i==0)gcd = i;}
  // Both numbers divided by gcd
  total[0] = total[0] / gcd;
  total[1] = total[1] / gcd;
  
  //If the total is ==, Return {n, 1}
  if (total[0] == total[1]){
    int *result;
    result = (int*)malloc(2*sizeof(int*));
    result[0] = total[0];
    result[1] = 1; 
    return result;
  }
  
  //Send the result as Pointer
  int *result;
  result = (int*)malloc(2*sizeof(int*));
  result[0] = total[0];
  result[1] = total[1]; 
return result;
}