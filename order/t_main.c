#include <stdio.h>
#include "s2i.h"


int main(int argc,char* argv[])
{
  //char *src_str = "hello world";
  double err[3] = {9.88, 7.3, 1.5};
  int vaild[4] = {1, 1, 0, 1};

  int min, mid, max, pmin, pmid, pmax;

  max_min_position(err,vaild, &min, &mid, &max, &pmin, &pmid, &pmax,3);
  printf("%d %d %d %d %d %d\n",min, mid, max, pmin, pmid, pmax);
  return 0;
}
