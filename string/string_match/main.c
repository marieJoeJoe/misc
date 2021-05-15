#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "string_pattern.h"

int main(int argc,char* argv[])
{


  struct timespec startcmp,endcmp,startmem,endmem;

  clock_gettime(CLOCK_MONOTONIC, &startcmp);
  for(int i; i < sizeof(modules)/sizeof(modules[0]);i++) //printf("[%p]\n",cmp_strstr(modules[i],pattern[i]));
  cmp_strstr(modules[i],pattern[i]);
  clock_gettime(CLOCK_MONOTONIC, &endcmp);

  clock_gettime(CLOCK_MONOTONIC, &startmem);
  for(int i; i < sizeof(modules)/sizeof(modules[0]);i++) //printf("[%p]\n",cmp_strstr(modules[i],pattern[i]));
  mem_strstr(modules[i],pattern[i]);
  clock_gettime(CLOCK_MONOTONIC, &endmem);


  printf("elapse %lu(nsec)\n",ts_to_long(endcmp)-ts_to_long(startcmp));
  printf("elapse %lu(nsec)\n",ts_to_long(endmem)-ts_to_long(startmem));

  return 0;
}
