#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"

#define DEBUG_PRINT //printf ("%d\n", __LINE__);

//#define TEST


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
    assert(equation);

    input_coeff(&(equation->a), 'a');
    input_coeff(&(equation->b), 'b');
    input_coeff(&(equation->c), 'c');

    // if (!input_coeff(&(equation->a), 'a'))
    // {
    //     return false;
    // }
    
    // if (!input_coeff(&(equation->b), 'b'))
    // {
    //     return false;
    // }

    // if (!input_coeff(&(equation->c), 'c'))
    // {
    //     return false;
    // }

    return true;
}

// bool input_coeff(double* coeff, char symbol)
// {
    // assert(coeff);

    // printf("Введите коэффициент %c\n%c = ", symbol, symbol);
    // scanf("%lf", coeff);
    // DEBUG_PRINT
    // char c = getchar();
    // DEBUG_PRINT

    // while (c != '\n' && c != '\t' && c != ' ') 
    // {
    //     if (c == EOF)
    //     {
    //         return false;
    //     }
    //     DEBUG_PRINT
    //     clear_buffer();
    //     DEBUG_PRINT
    //     printf("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
    //     DEBUG_PRINT
    //     scanf("%lf", coeff);
    //     c = getchar();


    // }
    // return true;

void input_coeff(double* coeff, char symbol)
{
    assert(coeff);

    printf("Введите коэффициент %c\n%c = ", symbol, symbol);
    DEBUG_PRINT
    // while ((scanf("%lf", coeff) != 1) && (getchar() != '\n'))
    while (scanf("%lf", coeff) != 1) 
    {
        DEBUG_PRINT
        clear_buffer();
        DEBUG_PRINT
        printf("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
    }

    clear_buffer();

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
    while (getchar() != '\n') continue;
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
