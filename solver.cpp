#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"
#include "solver.h"
#include "io.h"
#include "utils.h"


static ProgramStatus solve_linear(double k, double b, double* x1, RootsNumber* roots_num);


static ProgramStatus solve_linear(double k, double b, double* x1, RootsNumber* roots_num)
{
    assert(x1);

    if (!isfinite(k)) return INVALID_COEFF_B;
    if (!isfinite(b)) return INVALID_COEFF_C;

    if (is_null(k))
    {
        if (is_null(b)) *roots_num = INF_ROOTS;
        else *roots_num = ZERO_ROOTS;
    }
    else 
    {
        *x1 = -b/k;
        if (is_null(*x1)) *x1 = abs(*x1);
        *roots_num = ONE_ROOTS;
    }
    return OK;
}


ProgramStatus solve_square(SquareEquation* equation) 
{
    assert(equation);

    double a = equation->a;
    double b = equation->b;
    double c = equation->c;
    double* x1 = &equation->x1;

    if (!isfinite(a)) return INVALID_COEFF_A;
    if (!isfinite(b)) return INVALID_COEFF_B;
    if (!isfinite(c)) return INVALID_COEFF_C;


    if (is_null(a))
    {
        return solve_linear(b, c, x1, &(equation->roots_num)); 
    }
    
    double disc = b * b - 4 * a *c;
    if (disc < 0) equation->roots_num = ZERO_ROOTS;
    else if (is_null(disc))
    {
        *x1 = -b / (2*a);
        if (is_null(*x1)) *x1 = abs(*x1);
        equation->roots_num = ONE_ROOTS;
    }
    else
    {
        double* x2 = &equation->x2;
        double d_sqrt = sqrt(disc);
        *x1 = (-b + d_sqrt) / (2*a);
        *x2 = (-b - d_sqrt) / (2*a);
        if (is_null(*x1)) *x1 = abs(*x1);
        if (is_null(*x2)) *x2 = abs(*x2);
        equation->roots_num = TWO_ROOTS;
    }
    
    return OK;
}


void run_solver()
{
    struct SquareEquation equation = {};

    input_coeffs(&equation);
    solve_square(&equation); 
    output_roots(&equation);
}

