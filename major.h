#ifndef MAJOR_H
#define MAJOR_H

const double DELTA = 1e-5;

const char* const TEST = "test";
const char* const SOLVER = "solver";
const char* const HELP = "help";
const char* const TEST_FROM_FILE = "test_from_file";


enum NumArguments
{
    ONE_ARG = 1, 
    TWO_ARG
};

enum RootsNumber 
{
    INF_ROOTS = -1,
    ZERO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS
};

enum ProgramStatus {
    OK,
    INVALID_COEFF_A,
    INVALID_COEFF_B,
    INVALID_COEFF_C,
    ERROR_OPENING_FILE,
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