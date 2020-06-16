#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "s2i.h"

#define pr_info(fromat, ...) do{ printf("[%s]:"fromat, __FUNCTION__, ##__VA_ARGS__);}while (0)
/*
int string2integer(char * str, int * s2i)
{
  if(NULL == str) return -1;
  char* pstr = str;
  char symbol = ('-' != *pstr) ? 0 : 1;
  int ret = 0;
  while(*pstr != '\0')
  {
    if((*pstr < '0') || (*pstr > '9')) return -1;
    pr_info("%c\n",*pstr);
    ret *= 10;
  	ret += (*pstr - '0');
  	pstr++;
  }
  *s2i = ret;
  return 0;
}
*/

unsigned int str_length(char * str)
{
  unsigned int cnt = 0;
  if(NULL == str) return 0;
  while('\0' != *str++){
    cnt++;
  }
  return cnt;
}

int string2integer(char *str)
{
  int str2i = 0;
  int s_flag = 0;

  char* str_s = str;
  //char* str_e = str + strlen(str);
  char* str_e = str + str_length(str);



  while((!((*str_s>='0')&&(*str_s<='9')))&&('-' != *str_s)&&('+' != *str_s)&&( '\0' != *str_s)){
      //printf("%c\n",*str_s);
      if(' ' == *str_s) str_s++;
      else return 0;
  }
  int length = str_e - str_s;
  for(int i = 0; i<length; i++ )
  {
      if((0 == i) && ('-' == *(str_s+i))) s_flag = -1;
      else if ((0 == i) && ('+' == *(str_s+i))) s_flag = -2;

      if(-1 == s_flag)
      {
          if(0 != i)
          {

              if(!((*(str_s+i)>='0')&&(*(str_s+i)<='9'))) return str2i;
              if(str2i < INT_MIN/10)
              {
                  return INT_MIN;
              }
              else
              {
                  if(-(*(str_s + i)-'0') < (INT_MIN - 10*str2i)) return INT_MIN;
                  str2i = 10*str2i - (*(str_s + i)-'0');
              }
          }
      }
      else if(-2 == s_flag)
      {
          if(0 != i)
          {
              if(!((*(str_s+i)>='0')&&(*(str_s+i)<='9'))) return str2i;
              if(str2i > INT_MAX/10)
              {
                  return INT_MAX;
              }
              else
              {
                  if((*(str_s + i)-'0') > (INT_MAX - 10*str2i)) return INT_MAX;
                  str2i = 10*str2i + (*(str_s + i)-'0');
              }
          }
      }
      else
      {

          if(!((*(str_s+i)>='0')&&(*(str_s+i)<='9'))) return str2i;

          if(str2i > INT_MAX/10)
          {
              return INT_MAX;
          }
          else
          {
              if((*(str_s + i)-'0') > (INT_MAX - 10*str2i)) return INT_MAX;
              str2i = 10*str2i + (*(str_s + i)-'0');
          }
      }
  }
  return str2i;
}
