/*!
 * \file
 * \brief Файл, в котором реализуется ввод и вывод.
 * 
 * В этом файле собраны функции, в которых реализованы ввод и вывод в консоль.
 * Они используются в режиме проверки через терминал.
 */


#include <stdio.h>
#include <math.h>
#include <assert.h>


#include "io.h"
#include "colors.h"
#include "utils.h"


static void input_coeff(double* coeff, char symbol);

// scanf не поможет
// fgets, strtod, ... - ПРИЛОЖЕНИЕ Б К&R
static void input_coeff(double* coeff, char symbol)
{
    assert(coeff);

    PRINTF_CYAN("Введите коэффициент %c\n%c = ", symbol, symbol);

    while (scanf("%lf", coeff) != 1) 
    {
        clear_buffer();
        PRINTF_RED("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
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

// Добавить const! См io.h
void output_roots(SquareEquation* equation)
{
    assert(equation);

    switch(equation->roots_num)
    {
    case ZERO_ROOTS:
        PRINTF_YELLOW("Корней нет\n");
        break;

    case ONE_ROOTS:
        PRINTF_YELLOW("Один корень x = %lg\n", equation->x1);
        break;

    case TWO_ROOTS:
        PRINTF_YELLOW("Два корня: x1 = %lg, x2 = %lg\n", equation->x1, equation->x2);
        break;

    case INF_ROOTS:
        PRINTF_YELLOW("Корней бесконечное количество\n");
        break;

    default:
        PRINTF_RED("Что-то не то...");
        break;
    }
}
