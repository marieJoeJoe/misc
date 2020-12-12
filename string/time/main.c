#include <stdio.h>
#include <time.h>
#include <string.h>


char *temp = "20201213_001933_000";


int prefix(const char *pre, const char *str ,unsigned int ustrlen)
{
    return strncmp(pre, str, ustrlen) == 0;
}


int main(int argc,char* argv[])
{
  time_t rawtime;
  struct tm *info;

  char s_time[64]= {'\0'};

  time( &rawtime );
  info = localtime( &rawtime );

  printf("Current local time and date: %s", asctime(info));

  sprintf(s_time,"%4d%02d%02d_%02d%02d%02d_%03d",
		  info->tm_year + 1900,
		  info->tm_mon + 1,
		  info->tm_mday,
		  info->tm_hour ,
		  info->tm_min,
		  info->tm_sec,
		  0);

  printf("%s\n",s_time);

  int i = 0;

  
  printf("%s\n",temp);
  printf("%s\n",s_time);


  for(; i<20; i++){
     printf("%d\n",prefix(temp,s_time,i));
  }


  return 0;
}
