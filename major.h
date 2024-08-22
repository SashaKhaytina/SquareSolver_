#ifndef MAJOR_H
#define MAJOR_H

const double DELTA = 1e-5;

enum RootsNumber 
{
    INF_ROOTS,
    ZERO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS
};

enum ProgramStatus {
    OK,
    INVALID_COEFF_A,
    INVALID_COEFF_B,
    INVALID_COEFF_C,
};

struct SquareEquation 
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNumber roots_num;
};

#endif