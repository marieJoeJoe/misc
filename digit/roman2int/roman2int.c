#include <stdlib.h>
#include <string.h>
#include "roman2int.h"

int romanToInt(char * s){
    
    int res = 0;
    char curr_c = 0;
    char last_c = 0;

    char *p_end = s + strlen(s) - 1;
    //printf("%c\n",*p_end);
    
    for(char *i = p_end; i >= s; i--)
    {
        //printf("%c", *i);
        curr_c = *i;
        switch(curr_c)
        {
            case 'I':
            {
                if(('V' == last_c)||('X' == last_c)) res -= 1;
                else res += 1; 
                break;
            }
            case 'V':
            {
                res +=5; 
                break;
            }
            case 'X':
            {
                if(('L' == last_c)||('C' == last_c)) res -= 10;
                else res += 10; 
                break;
            }
            case 'L':
            {
                res +=50; 
                break;
            }
            case 'C':
            {
                if(('D' == last_c)||('M' == last_c)) res -= 100;
                else res += 100; 
                break;
            }
            case 'D':
            {
                res +=500; 
                break;
            }
            case 'M': 
            {
                res +=1000; 
                break;
            } 
            default:
                break;
        }
        last_c = *i;
    }
    //printf("\n");
    return res;
}


