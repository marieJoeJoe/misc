#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * clear(char* str)
{
  int j = 0;
  for(int i = 0; i< strlen(str); i++)
  {
    if(str[i] != '#'){
      str[j] = str[i];
      j++;
    }else{
      if(j > 0){
        j--;
      }
    }
  }
  str[j] = '\0';
  return str;
}

int backspaceCompare(char * S, char * T)
{
  return ( 0 == strcmp(clear(S), clear(T) ) );
}

int main(int argc, char* argv[])
{

  char S[] = "ab#c", T[] = "ad#c";

  printf("%d\n",backspaceCompare(S,T));


}
