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

// Function to implement `strstr()` function using KMP algorithm
const char* kmp_strstr(const char* X, const char* Y, int m, int n)
{
    // base case 1: `Y` is NULL or empty
    if (*Y == '\0' || n == 0) {
        return X;
    }
 
    // base case 2: `X` is NULL, or X's length is less than Y's
    if (*X == '\0' || n > m) {
        return NULL;
    }
 
    // `next[i]` stores the index of the next best partial match
    int next[n + 1];
 
    for (int i = 0; i < n + 1; i++) {
        next[i] = 0;
    }
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
 
        while (j > 0 && Y[j] != Y[i]) {
            j = next[j];
        }
 
        if (j > 0 || Y[j] == Y[i]) {
            next[i + 1] = j + 1;
        }
    }
 
    for (int i = 0, j = 0; i < m; i++)
    {
        if (*(X + i) == *(Y + j))
        {
            if (++j == n) {
                return (X + i - j + 1);
            }
        }
        else if (j > 0)
        {
            j = next[j];
            i--;    // since `i` will be incremented in the next iteration
        }
    }
    return NULL;
}


