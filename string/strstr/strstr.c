#include "stdio.h"
#include "strstr.h"

#define pr_info(fromat, ...) do{ printf("[%s]:"fromat, __FUNCTION__, ##__VA_ARGS__);}while (0)

int compare(const char* X, const char* Y)
{
  while(*X && *Y)
  {
    if(*X != *Y) return 0;
    X++;
    Y++;
  }

  return (*Y == '\0');

}


const char* strstr(const char* X, const char* Y)
{
  while(*X != '\0' )
  {
    if((*X == *Y) && compare(X,Y))
	    return X;
    X++;
  }

  return NULL;

}
