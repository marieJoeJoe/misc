#include <stdio.h>

int maxProfit(int* prices, int pricesSize);

int main(int argc, char* argv[])
{

  int s1[] = {7, 1, 5, 3, 6, 4};

  int s2[] = {1, 2, 3, 4, 5};

  printf("%d\n", maxProfit( s1, sizeof(s1)/sizeof(s1[0])) );
  printf("%d\n", maxProfit( s2, sizeof(s2)/sizeof(s2[0])) );

  return 0;
}


int maxProfit(int* prices, int pricesSize){

  int total = 0;

  for(int i = 0; i+1 < pricesSize; i++){
    if(prices[i] < prices[i+1]){
      total += prices[i+1] - prices[i];
    }
  }
  return total;
}