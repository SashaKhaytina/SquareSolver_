#ifndef UTILS
#define UTILS

#include <stdio.h>
#include "major.h"

bool is_null(double n);
bool is_equally(double a, double b);
ProgramStatus open_file(FILE **file);
void clear_buffer();

#endif