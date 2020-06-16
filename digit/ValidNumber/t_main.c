
#include <stdio.h>
#include "vn.h"
/* Driver program to test above function */
int main() 
{ 
/*
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false
*/

  int sdata = 0;
  printf("%s\t, %d\n", (0 == validNumChecker("0",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker(" 0.1 ",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("abc",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("1 a",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("2e10",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker(" 1e",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("e3",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker(" 6e-1",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker(" 99e2.5 ",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("53.5e93",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker(" --6 ",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("-+3",&sdata)) ?"false":"true",sdata);
  printf("%s\t, %d\n", (0 == validNumChecker("95a54e53",&sdata)) ?"false":"true",sdata);
  return 0; 
} 
