/*!
 * \file
 * \brief Файл с описанием вывода возможных ошибок.
 */


#include <stdio.h>

#include "utils.h"
#include "errors.h"


void print_error_code(ProgramStatus status)
{
    if      (status == INVALID_COEFF_A)    PRINTF_RED("Коэффициент a неверный\n");
    else if (status == INVALID_COEFF_B)    PRINTF_RED("Коэффициент b неверный\n");
    else if (status == INVALID_COEFF_C)    PRINTF_RED("Коэффициент c неверный\n");
    else if (status == ERROR_OPENING_FILE) PRINTF_RED("Неудалось открыть файл\n");
    else if (status == ERROR_CLOSING_FILE) PRINTF_RED("Неудалось закрыть файл\n");
    else if (status == ERROR_COMAND)       PRINTF_RED("Ошибка ввода в командной строке. Введите команду еще раз (./square help - помощь)\n");
    else                                   PRINTF_GREEN("Программа завершила работу без ошибок\n");
}