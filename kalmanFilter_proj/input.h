#ifndef __INPUT_H__
#define __INPUT_H__

#include <stdio.h>
#include <stdlib.h>

FILE* open_file(char*);


void get_one_mesure_value( FILE*, float * );

void close_file(FILE*);

#endif
