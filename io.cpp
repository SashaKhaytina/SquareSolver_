#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"
#include "io.h"

static void clear_buffer();
static void input_coeff(double* coeff, char symbol);


static void clear_buffer()
{
    while (getchar() != '\n') continue; // if EOF also break
}


static void input_coeff(double* coeff, char symbol)
{
    assert(coeff);

    printf("Введите коэффициент %c\n%c = ", symbol, symbol);

    while (scanf("%lf", coeff) != 1) 
    {
        clear_buffer();
        printf("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
    }

    clear_buffer();
}


void input_coeffs(SquareEquation* equation)
{
    assert(equation);

    input_coeff(&(equation->a), 'a');
    input_coeff(&(equation->b), 'b');
    input_coeff(&(equation->c), 'c');
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
