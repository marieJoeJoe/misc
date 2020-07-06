#include <stdio.h>

int next_n(int );
int isHappy(int );


int main(int argc, char* argv[])
{
  printf("%d\n",isHappy(19));

  return 0;
}


int next_n(int n)
{
  int r  =0;
  while(0 != n){
    int d = n%10;
    n /= 10;
    r += d * d;
  }
  return r;
}

int isHappy(int n)
{
  int slow = n;
  int fast = n;

  do{
    slow = next_n(slow);
    fast = next_n(next_n(fast));
  }while(slow != fast);
  
  return (1==fast);
}
