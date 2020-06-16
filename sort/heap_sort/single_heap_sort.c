#include <stdio.h>
#include <memory.h>
#include <gsl/gsl_rng.h>

#include "heap.h"

#define RND_DATA_LEN 7


unsigned int rnd_data[RND_DATA_LEN+1]={0};
unsigned int sorted_data[RND_DATA_LEN+1]={0};


void printf_line(unsigned int* idata, unsigned int len);
void swap_data(unsigned int* l, unsigned int* r);
void single_heap_sort(unsigned int* idata, unsigned int* odata, unsigned int len);


int main(int argc,char* argv[])
{
    const gsl_rng_type * T;
    gsl_rng * r;                                         
    int i, n = 10;                                                   
    gsl_rng_env_setup();       
    T = gsl_rng_default;                                                            

    r = gsl_rng_alloc(T);                                                          

    memset(rnd_data,0,sizeof(rnd_data));
    memset(sorted_data,0,sizeof(sorted_data));

    for (i = 1; i < RND_DATA_LEN+1; i++)	    
    {
        double u = gsl_rng_uniform (r);                                             
	rnd_data[i] = ((int)(u*100000));                                            
	printf ("%d\n",rnd_data[i]);                                              
    }
    
    single_heap_sort(rnd_data, sorted_data, RND_DATA_LEN+1);
    
    
    printf("result:\n");
    for(i = 1; i<RND_DATA_LEN+1; i++)
	    printf("%d\n",sorted_data[i]);
    return 0;
}
void printf_line(unsigned int* idata, unsigned int len)
{
    unsigned int i= 0;
    for(i = 1; i<len; i++)
    {
        printf("%d\t",idata[i]);
    }
    printf("\n");
}

void swap_data(unsigned int* l, unsigned int* r)
{
	unsigned int tmp;
	tmp = *r;
	*r = *l;
        *l = tmp;
}

void single_heap_sort(unsigned int* idata, unsigned int* odata, unsigned int len)
{

    unsigned int i,j,child,lastElement;
    for(i = 1; i<len; i++)
    {
	odata[i] = idata[i];
    
        for(j = i; odata[j/2]>odata[j]; j /= 2)
	{
            swap_data(&odata[j/2],&odata[j]);
	}
    }

    printf("heap:\n");
    printf_line(odata,len);
    printf("\n");

    for(i = 1; i<len; i++)
    {
        swap_data(&odata[1],&odata[len - i]);
        printf_line(odata,len);
	lastElement=odata[1];
        for(j = 1; j*2 <(len-i-1); j=child)
	{
            child = j*2 +2;

            //printf_line(odata,len);
	    if((child <= (len -i-1))&&(odata[child]<odata[child-1]))
                child--;

	    if(lastElement>odata[child])
                odata[j] = odata[child];
	    else
                break;
	}
	odata[j] = lastElement;
    }
}

