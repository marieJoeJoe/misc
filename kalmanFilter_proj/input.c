#include "input.h"


FILE* open_file(char* file_path){

  FILE *fp;
  if( (fp = fopen(file_path,"r")) == NULL ){
    exit(1);
  }

  return fp;
}

void get_one_mesure_value(FILE* fp, float * value ){


}


void close_file(FILE* fp){

  if(NULL != fp) fclose(fp);

}
