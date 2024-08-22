#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"
#include "solver.h"
#include "io.h"
#include "tester.h"

#define TEST 

int main()
{
    // ax^2 + bx + c = 0

    #ifdef TEST

    run_all_tests();

    #else

    struct SquareEquation equation = {};

    input_coeffs(&equation);

    solve_square(&equation); 

    output_roots(&equation);

    #endif
    
    return 0;
}