#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"
#include "colors.h"
#include "utils.h"

bool is_null(double n)
{
    if (abs(n) < DELTA) 
        return true;
    return false;
}


bool is_equally(double a, double b)
{
    return (abs(a - b) < DELTA); 
}


ProgramStatus open_file(FILE **file)
{
    assert(file);
    
    *file = fopen("tests.txt", "r");
    if (*file == NULL) return ERROR_OPENING_FILE;
    return OK;
}


void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n')
    {
        if (c == EOF) break;
        continue;

    }
}