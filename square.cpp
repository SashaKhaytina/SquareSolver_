#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"

#define DEBUG_PRINT printf ("%d\n", __LINE__);

#define TEST

/*
#define fun() \
    printf("hey");


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
void input_coeff(double* coeff, char symbol);
void output_roots(SquareEquation* equation);
bool is_null(double n);
bool is_equally(double a, double b);
void clear_buffer();
AnyErrors solve_linear(double k, double b, double* x1, RootsNumber* roots_num);  // kx + b = 0
void run_all_tests();
CheckTest run_test(const SquareEquation* expected, double* t_x1, double* t_x2, RootsNumber* t_roots_num);
void print_test_result(const SquareEquation* expected, double t_x1, double t_x2, RootsNumber t_roots_num, int test_number, CheckTest checker);
*/

//#include "Tester.cpp"

//void print_test_result(CheckTest checker, int test_number);
/*
const struct SquareEquation TESTS[] = {
    {0, 0, 0, 0, 0, INF_ROOTS}, 
    {1, 3, 2, -1, -2, TWO_ROOTS}, 
    {0, 7, 0, 0, 0, ONE_ROOTS}, 
    {1, 1, 1, 0, 0, ZERO_ROOTS},
    {0, 7, 0, 5, 5, TWO_ROOTS},
    {7, 0, 7, 0, 0, ZERO_ROOTS}
};
*/

int main()
{
    // ax^2 + bx + c = 0

    #ifdef TEST

    run_all_tests();

    #else

    struct SquareEquation equation = {};

    if (!input_coeffs(&equation))
    {
        printf("Недостаточно правильных коэффициентов. Запустите заново\n");
        return 0;
    }

    solve_square(&equation); 

    output_roots(&equation);

    #endif
    
    return 0;
}

bool input_coeffs(SquareEquation* equation)
{
    if (!input_coeff(&(equation->a), 'a'))
    {
        return false;
    }
    
    if (!input_coeff(&(equation->b), 'b'))
    {
        return false;
    }

    if (!input_coeff(&(equation->c), 'c'))
    {
        return false;
    }

    return true;
}

bool input_coeff(double* coeff, char symbol)
{
    assert(coeff);

    printf("Введите коэффициент %c\n%c = ", symbol, symbol);
    scanf("%lf", coeff);
    DEBUG_PRINT;
    char c = getchar();
    DEBUG_PRINT

    while (c != '\n' && c != '\t' && c != ' ') 
    {
        if (c == EOF)
        {
            return false;
        }
        DEBUG_PRINT
        clear_buffer();
        DEBUG_PRINT
        printf("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
        DEBUG_PRINT
        scanf("%lf", coeff);
        c = getchar();


    }
    return true;
}


AnyErrors solve_square(SquareEquation* equation) 
{
    assert(equation);
    // сравнение чисел с точкой!
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;
    double* x1 = &equation->x1;

    if (!isfinite(a)) return A_IS_NOT_NUM;
    if (!isfinite(b)) return B_IS_NOT_NUM;
    if (!isfinite(c)) return C_IS_NOT_NUM;


    if (is_null(a))
    {
        //equation->roots_num = solve_linear(b, c, x1);
        solve_linear(b, c, x1, &(equation->roots_num)); ////////////////////// Куда-то сохранять ошибку? ///////////////////////////////////
    }
    else
    {
        double disc = b * b - 4 * a *c;
        if (disc < 0) equation->roots_num = ZERO_ROOTS;
        else if (is_null(disc))
        {
            *x1 = -b / (2*a);
            equation->roots_num = ONE_ROOTS;
        }
        else
        {
            double* x2 = &equation->x2;
            double d_sqrt = sqrt(disc);
            *x1 = (-b + d_sqrt) / (2*a);
            *x2 = (-b - d_sqrt) / (2*a);
            equation->roots_num = TWO_ROOTS;
        }
    }
    return ALL_OK;
}


void output_roots(SquareEquation* equation)
{
    assert(equation);

    switch(equation->roots_num)
    {
    case ZERO_ROOTS:
        printf("Корней нет\n");
        break;

    case ONE_ROOTS:
        printf("Один корень x = %lg\n", equation->x1);
        break;

    case TWO_ROOTS:
        printf("Два корня: x1 = %lg, x2 = %lg\n", equation->x1, equation->x2);
        break;

    case INF_ROOTS:
        printf("Корней бесконечное количество\n");
        break;

    default:
        printf("Что-то не то...");
        break;
    }
}


bool is_null(double n)
{
    if (abs(n) < DELTA) return true;
    return false;
}

bool is_equally(double a, double b)
{
    return (abs(a - b) < DELTA); 
}


void clear_buffer()
{
    char c = getchar();
    while (c != '\n' && c != EOF) continue;
}


AnyErrors solve_linear(double k, double b, double* x1, RootsNumber* roots_num)
{
    assert(x1);

    if (!isfinite(k)) return B_IS_NOT_NUM;
    if (!isfinite(b)) return C_IS_NOT_NUM;

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
    return ALL_OK;
}

/*
void print_test_result(const SquareEquation* expected, double t_x1, double t_x2, RootsNumber t_roots_num, int test_number, CheckTest checker)
{
    assert(expected);

    if (checker) printf("Test %d - OK\n", test_number + 1);
    else
    {
        printf("Test %d - ERROR\nError test: x1 = %lg, x2 = %lg, nRoots = %d\n"
           "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n", 
           test_number, t_x1, t_x2, t_roots_num, expected->x1, expected->x2, expected->roots_num);
    }

}

CheckTest run_test(const SquareEquation* expected, double* t_x1, double* t_x2, RootsNumber* t_roots_num)
{
    assert(expected);
    assert(t_x1);
    assert(t_x2);
    assert(t_roots_num);

    SquareEquation test = {expected->a, expected->b, expected->c, 0, 0};
    solve_square(&test);

    bool check_x1 = is_equally(test.x1, expected->x1);
    bool check_x2 = is_equally(test.x2, expected->x2);
    bool check_roots_num = is_equally(test.roots_num, expected->roots_num);

    *t_x1 = test.x1;
    *t_x2 = test.x2;
    *t_roots_num = test.roots_num;

    if (check_x1 && check_x2 && check_roots_num) return TEST_OK;
    else
    {
        //error_test(expected, test.x1, test.x2, test.roots_num);
        return TEST_ERROR;
    }
}

void run_all_tests()
{
    int quantity_tests = sizeof(TESTS) / sizeof(SquareEquation);

    for (int test_number = 0; test_number < quantity_tests; test_number++)
    {
        double t_x1 = 0, t_x2 = 0;
        RootsNumber t_roots_num = ZERO_ROOTS;

        const SquareEquation* test_i = &(TESTS[test_number]);
        CheckTest checker = run_test(test_i, &t_x1, &t_x2, &t_roots_num);
        print_test_result(test_i, t_x1, t_x2, t_roots_num, test_number, checker);

    }
}
*/