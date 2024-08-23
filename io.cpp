#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "major.h"
#include "io.h"
#include "colors.h"
#include "utils.h"


static void input_coeff(double* coeff, char symbol);


static void input_coeff(double* coeff, char symbol)
{
    assert(coeff);

    CYAN("Введите коэффициент %c\n%c = ", symbol, symbol);

    while (scanf("%lf", coeff) != 1) 
    {
        clear_buffer();
        RED("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
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
        YELLOW("Корней нет\n");
        break;

    case ONE_ROOTS:
        YELLOW("Один корень x = %lg\n", equation->x1);
        break;

    case TWO_ROOTS:
        YELLOW("Два корня: x1 = %lg, x2 = %lg\n", equation->x1, equation->x2);
        break;

    case INF_ROOTS:
        YELLOW("Корней бесконечное количество\n");
        break;

    default:
        RED("Что-то не то...");
        break;
    }
}
