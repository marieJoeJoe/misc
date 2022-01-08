
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char *argv[])
{
  if(argc != 2){
    printf("./reverse \"a string\"\n");
    return -1;
  }  

  int strbuf_len =  strlen(argv[1])+1;

  char* input = malloc(strbuf_len);

  strncpy(input,argv[1],strbuf_len);


  char* output = malloc(strbuf_len);

  memset(output, '\0', strbuf_len);

  char *pin=input, *pout = output + strbuf_len - 2;

  while(*pin != '\0') *pout-- = *pin++;

  printf("in  [%s]\n",input);
  printf("out [%s]\n",output);

  //char* hello = input;

  free(input);
  free(output);


  //strncpy(hello,argv[1],strbuf_len);
  //printf("%s\n",hello);

  //printf("hello world!!\n");

  return 1;  


}
