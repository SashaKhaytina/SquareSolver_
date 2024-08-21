#ifndef MAJOR_H
#define MAJOR_H

const double DELTA = 1e-7;

enum RootsNumber 
{
    INF_ROOTS,
    ZERO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS
};

enum CheckTest 
{
    TEST_ERROR,
    TEST_OK
};

enum AnyErrors
{
    A_IS_NOT_NUM,
    B_IS_NOT_NUM,
    C_IS_NOT_NUM,
    ALL_OK
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

AnyErrors solve_square(SquareEquation* equation);
bool input_coeff(double* coeff, char symbol);
bool input_coeffs(SquareEquation* equation);
void output_roots(SquareEquation* equation);
bool is_null(double n);
bool is_equally(double a, double b);
void clear_buffer();
AnyErrors solve_linear(double k, double b, double* x1, RootsNumber* roots_num);  // kx + b = 0
void run_all_tests();
CheckTest run_test(const SquareEquation* expected, double* t_x1, double* t_x2, RootsNumber* t_roots_num);
void print_test_result(const SquareEquation* expected, double t_x1, double t_x2, RootsNumber t_roots_num, int test_number, CheckTest checker);


#endif