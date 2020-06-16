#include "rs.h"
#include <stdio.h>
#include <stdlib.h>

#define pr_info(fromat, ...) do{ printf("[%s]:"fromat, __FUNCTION__, ##__VA_ARGS__);}while (0)

unsigned int str_length(char * str)
{
  unsigned int cnt = 0;
  if(NULL == str) return 0;
  while('\0' != *str++){
    cnt++;
  }
  return cnt;
}

void reverse_string( char * src_str,char * dst_str,int m)
{
  if(m != str_length(src_str)){
    pr_info("src_str length error!!\n");
    return;
  }
  //pr_info("%s %u\n",src_str,str_length(src_str));
  char *psrc = src_str + m - 1;
  //pr_info("%c\n",*psrc);
  do{
  *dst_str++ = *psrc--;
  }while(m--);
  *(dst_str+1)='\0';
}


void reverse_string_inplace( char * str)
{

  unsigned int str_len, from, to;

  if((str_len = str_length(str)) == 0){
    pr_info("src_str length error!!\n");
    return;
  }
  printf("%s\n", str );
  to = str_len - 1;
  from = 0;
  //pr_info("%d\n",str_len);
  //pr_info("%s %u\n",src_str,str_length(src_str));
  //char *psrc = str;
  //pr_info("%c\n",*psrc);
  while( from < to ){
    char t = str[from];
    str[from++] = str[to];
    //printf("%c%c ",t,str[to]);
    str[to--] = t;
  }
  //printf("%s\n", str );
}


void reverse_string_inplace_by_index( char * str, int m, int n )
{

  unsigned int str_len, from, to;

  if((str_len = str_length(str)) == 0){
    pr_info("src_str length error!!\n");
    return;
  }

  from = m;
  to = n;

  while( from < to ){
    char t = str[from];
    str[from++] = str[to];
    str[to--] = t;
  }
}


void leftrotate_string( char * str, int m)
{
  int len = str_length(str) - 1;
  if( m >= len ) pr_info("rotate pos error!!\n");
  reverse_string_inplace_by_index(str,0,m);
  reverse_string_inplace_by_index(str,m+1,len);
  reverse_string_inplace_by_index(str,0,len);
}
