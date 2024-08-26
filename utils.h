/*!
 * \file
 * \brief Вспомогательные функции.
 */


#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include "errors.h"

#define PRINTF_RED(string, ...)     printf("\x1b[31m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста красным цветом. */
#define PRINTF_GREEN(string, ...)   printf("\x1b[32m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста зеленым цветом. */
#define PRINTF_YELLOW(string, ...)  printf("\x1b[33m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста желтым цветом. */
#define PRINTF_BLUE(string, ...)    printf("\x1b[34m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста синим цветом. */
#define PRINTF_MAGENTA(string, ...) printf("\x1b[35m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста цветом маджента. */
#define PRINTF_CYAN(string, ...)    printf("\x1b[36m" string "\x1b[0m", ##__VA_ARGS__)    /*!< Печать текста цветом циан. */


const double DELTA = 1e-5;    /*!< Значение погрешности. */


/*!
 * \brief Функция, которая проверяет равно ли число типа double 0.
 * 
 * Возвращает true, если число равно 0, и false, если не равно (с учетом погрешности).
 * \param[in] n - число типа double, для которого происходит проверка.
 * \return Возвращает переменную типа bool.
 */
bool is_null(double n);


/*!
 * \brief Функция, которая проверяет равнество своих аргументов типа double.
 * 
 * Возвращает true, если числа равны, и false, если не равны (с учетом погрешности).
 * \param[in] a - первый аргумент типа double.
 * \param[in] b - второй аргумент типа double.
 * \return Возвращает переменную типа bool.
 */
bool are_equal(double a, double b);


/*!
 * \brief Функция, которая сравнивает число типа double с 0.
 * 
 * Функция сравнивает число типа double с 0 с учетом погрешности. 
 * Если число больше 0, функция вернет 1 \n
 * Если число равно 0, функция вернет 0 \n
 * Если число меньше 0, функция вернет -1 \n 
 * \param[in] a - число типа double, которое сравнивается с 0.
 * \return Возвращает переменную типа int.
 */
int get_sign_double(double a);


/*!
 * \brief Функция, которая открывает переданный файл для чтения.
 * 
 * \param[out] file - файл, открываемй для чтения.
 * \return Возвращает переменную типа ProgramStatus, которая показывает успешность открытия файла (ОК или какая-либо ошибка).
 */
ProgramStatus open_file(FILE **file, const char* file_name, const char* format);


/*!
 * \brief Функция, которая очищает буфер.
 * 
 * Перемещает курсор на положение, которое находится сразу после близжайшего '\\n' Перемещая, отслеживает, встречались ли сторонник символы
 * (не пробелы).
 * 
 * \return Возвращает переменную типа bool. (true - если не встречала, false - если встречала).
 */
bool clear_buffer();


#endif