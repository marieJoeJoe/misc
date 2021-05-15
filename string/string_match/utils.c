#include <stdlib.h>
#include <string.h>
#include <time.h>

long ts_to_long(struct timespec t) {
  return t.tv_sec * 1000000000 + t.tv_nsec;
}


int compare(const char *X, const char *Y)
{
    while (*X && *Y)
    {
        if (*X != *Y) {
            return 0;
        }
        X++;
        Y++;
    }
    return (*Y == '\0');
}
 
// Function to implement `strstr()` function
const char* cmp_strstr(const char* X, const char* Y)
{
    while (*X != '\0')
    {
        if ((*X == *Y) && compare(X, Y)) {
            return X;
        }
        X++;
    }
    return NULL;
}

// Function to implement `strstr()` function
const char* mem_strstr(const char *X, const char *Y)
{
    size_t n = strlen(Y);
 
    while (*X)
    {
        if (!memcmp(X, Y, n)) {
            return X;
        }
 
        X++;
    }
 
    return 0;
}




