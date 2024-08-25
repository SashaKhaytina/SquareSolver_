#ifndef MAJOR_SOLVER_H
#define MAJOR_SOLVER_H

#include "status.h"


enum RootsNumber 
{
    INF_ROOTS = -1,    /*!< Означает бесконечное количество корней. */
    ZERO_ROOTS,        /*!< Означает ноль корней. */
    ONE_ROOTS,         /*!< Означает один корень. */
    TWO_ROOTS          /*!< Означает два корня. */
};


/*!
 * Структура, описывающая квадратное уравнение.
 */
struct SquareEquation 
{
    double a;                   /*!< Коэффициент a (при x^2). */
    double b;                   /*!< Коэффициент b (при x). */
    double c;                   /*!< Коэффициент с (свободный член). */
    double x1;                  /*!< Первый действительный корень квадратного уравнения. */
    double x2;                  /*!< Второй действительный корень квадратного уравнения. */
    RootsNumber roots_num;      /*!< Количество действительных корней уравнения. */
};


/*!
 * \brief Функция, которая считает корни квадратного уравнения
 * 
 * Функция рассматривает так же случай, когда уравнение линейное
 * 
 * \param[out] equation - структура квадратного уравнения
 * \see solve_linear(double k, double b, double* x1, RootsNumber* roots_num)
 * \see bool is_null(double n)
 * \return Возвращает успешность выполнения (ОК или какая-либо ошибка)
 */
ProgramStatus solve_square(SquareEquation* equation);

/*!
 * \brief Функция, которая запускает функции для режима проверки через терминал.
 * 
 * Функция рассматривает так же случай, когда уравнение линейное.
 * 
 * \see input_coeffs(&equation)
 * \see solve_square(&equation)
 * \see output_roots(&equation)
 */
void run_solver();

#endif
