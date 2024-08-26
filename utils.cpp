/*!
 * \file
 * \brief Вспомогательные функции (описание).
 */


#include "utils.h"

#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "errors.h"


bool is_null(double n)
{
    return are_equal(n, 0);
}


bool are_equal(double a, double b)
{

    return (fabs(a - b) < DELTA); 
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


bool clear_buffer()
{
    int c = 0;
    int flag = 0;
    
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (c != '\n' && c != '\t' && c != ' ') flag = 1;
        continue;
    }
    if (flag) return false;
    return true;
}


int get_sign_double(double a)
{
    if (a < (-DELTA))   return -1;
    else if (a > DELTA) return 1;
    else                return 0;
}
