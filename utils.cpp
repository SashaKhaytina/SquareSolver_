/*!
 * \file
 * \brief Вспомогательные функции.
 */


#include "utils.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "status.h"
#include "colors.h"



bool is_null(double n)
{
    if (abs(n) < DELTA) 
        return true;
    return false;
}


bool are_equal(double a, double b)
{
    return (abs(a - b) < DELTA); 
}


ProgramStatus open_file(FILE **file, const char* file_name, const char* format)
{
    assert(file);
    assert(file_name);
    assert(format);
    
    *file = fopen(file_name, format);
    if (*file == NULL) return ERROR_OPENING_FILE;
    return OK;
}


void clear_buffer()
{
    int c = 0;
    while ((c = getchar()) != '\n')
    {
        if (c == EOF) break;
        continue;

    }
}


int get_sign_double(double a)
{
    if (a < (-DELTA)) return -1;
    else if (a > DELTA) return 1;
    else return 0;
}