/*!
 * \file
 * \brief Файл, в котором заданы функции для ввода и вывода.
 */


#ifndef MAJOR_IO_H
#define MAJOR_IO_H

#include "solver.h"


/*!
 * \brief Функция, которая производит ввод коэффициентов квадратного уравнения через командную строку.
 * 
 * \param[out] equation - это структура квадратного уравнения, в которую водятся коэффициенты.
 */
void input_coeffs(SquareEquation* equation);


/*!
 * \brief Функция, которая производит вывод посчитанных корней уравнений и их количества в командную строку.
 * 
 * \param[in] equation - это структура квадратного уравнения, для котоорого выводятся ответы и их количество. 
 */
void output_roots(const SquareEquation* equation);

#endif