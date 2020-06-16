#include <stdlib.h>
#include <string.h>
#include "int2roman.h"

char * intToRoman(int num)
{

    char *res = (char *)malloc(20);
    char *p = res;
    int target = num;
    int checknum = 0;
    memset(res,'\0',20);
  
    while(target != 0){
        //printf("%d\n",target);
        if((checknum = target/1000)>0)
        {
            target = target - 1000*checknum;
            for(; checknum!=0; checknum--) *p++ = 'M'; 
        }
        else if((checknum = target/900)>0)
        {
            target = target - 900*checknum;
            for(; checknum!=0; checknum--){
              *p++ = 'C'; 
              *p++ = 'M';
            }
            
        }
        else if((checknum = target/500)>0)
        {
            target = target - 500*checknum;
            for(; checknum!=0; checknum--) *p++ = 'D'; 
        }
        else if((checknum = target/400)>0)
        {
            target = target - 400*checknum;
            for(; checknum!=0; checknum--)
            {
              *p++ = 'C'; 
              *p++ = 'D';
            }
        }
        else if((checknum = target/100)>0)
        {
            target = target - 100*checknum;
            for(; checknum!=0; checknum--) *p++ = 'C'; 
        }
        else if((checknum = target/90)>0)
        {
            target = target - 90*checknum;
            for(; checknum!=0; checknum--)
            {
              *p++ = 'X'; 
              *p++ = 'C';
            }
        }
        else if((checknum = target/50)>0)
        {
            target = target - 50*checknum;
            for(; checknum!=0; checknum--) *p++ = 'L'; 
        }
        else if((checknum = target/40)>0)
        {
            target = target - 40*checknum;
            for(; checknum!=0; checknum--)
            {
              *p++ = 'X'; 
              *p++ = 'L';
            }
        }
        else if((checknum = target/10)>0)
        {
            target = target - 10*checknum;
            for(; checknum!=0; checknum--) *p++ = 'X'; 
        }
        else if((checknum = target/9)>0)
        {
            target = target - 9*checknum;
            for(; checknum!=0; checknum--)
            {
              *p++ = 'I'; 
              *p++ = 'X';
            }
        }
        else if((checknum = target/5)>0)
        {
            target = target - 5*checknum;
            for(; checknum!=0; checknum--) *p++ = 'V'; 
        }
        else if((checknum = target/4)>0)
        {
            target = target - 4*checknum;
            for(; checknum!=0; checknum--)
            {
              *p++ = 'I'; 
              *p++ = 'V';
            }
        } 
        else if((checknum = target)>0)
        {
            target = target - checknum;
            for(; checknum!=0; checknum--) *p++ = 'I'; 
        } 
    }
 
    return res;
}

