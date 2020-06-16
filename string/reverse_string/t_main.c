#include <stdio.h>
#include <memory.h>
#include <gsl/gsl_rng.h>

#include "rs.h"


int main(int argc,char* argv[])
{
  //char *src_str = "hello world";
  char *src_str="Thesubstitutecommandisappliedtothelinesmatchingtheaddress.Ifnoaddressisspecified,itisappliedtoalllinesthatmatchthepattern,aregularexpression";
  char *dst_str = (char *)malloc(strlen(src_str)+1);
  char *ip_str = (char *)malloc(strlen(src_str)+1);

  reverse_string(src_str,dst_str, strlen(src_str));

  strcpy(ip_str,src_str);
  printf("%s\n",ip_str);
  //reverse_string_inplace(ip_str);
  //reverse_string_inplace_by_index(ip_str,0,77);
  leftrotate_string(ip_str,77);
  printf("%s\n",ip_str);

  //reverse_string_inplace_by_index(ip_str,78,140-1);
  //printf("%s\n",ip_str);


  return 0;
}
