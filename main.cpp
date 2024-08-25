/*!
 * \file
 * \brief Главный файл, запускающий программу.
 */

// doxygen and doxywisard
// man doxywizard
// doxywizard - для запуска!!!

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "status.h"
#include "solver.h"
#include "io.h"
#include "tester.h"
#include "colors.h"


/*! Тип перечисление.
 * 
 *  Перечисление возможных вариантов количества аргументов командной строки.
 */
// в main.cpp
enum NumArguments
{
    ONE_ARG = 1,    /*!< Означает, что передан один аргумент. */
    TWO_ARG         /*!< Означает, что передано два аргумента. */
};


const char* const TEST   = "test";      /*!< Аргумент командной строки, который надо передать для запуска режима автоматической проверки. */
const char* const SOLVER = "solver";    /*!< Аргумент командной строки, который надо передать для запуска режима проверки через терминал. */
const char* const HELP   = "help";      /*!< Аргумент командной строки, который надо передать для запуска режима помощи. */


/*! \brief Функция, которая запускает режимы программы.
 * 
 * В зависимости от аргументов запускаются разные режимы: \n
 * - Режим автоматического тестирования \n
 * - Режим проверки через терминал \n
 * - Режим помощи \n
 * - Сообщение об ошибке 
 * 
 * \param[in] argc Количество аргументов командной строки.
 * \param[in] argv Аргументы командной строки.
*/
void run_programm(int argc, const char *argv[]);


/*! \brief Функция, которая запускает режим помощи.
 * 
 *  Выводит список всех возможных команд и их описание.
 */
void help_mode();


/*! \brief Функция, которая выводит сообщение об ошибке ввода команды.*/
void command_error();


// cdecl

/*! \brief Функция, которая запускает программу.
 * 
 *  \param[in] argc - количество аргументов командной строки
 *  \param[in] argv - массив строк размером argc, в котором лежат аргументы командной строки.
 *  \see run_programm(int argc, const char *argv[])
 */
int main(int argc, const char *argv[])
{
    // ax^2 + bx + c = 0

    run_programm(argc, argv);
}

// FIXME: функции возвращают ошибки, но мы на это забили
void run_programm(int argc, const char *argv[])
{
    if (argc == TWO_ARG) 
    {
        if      (strcmp(argv[1], TEST)   == 0) run_all_tests();
        else if (strcmp(argv[1], SOLVER) == 0) run_solver();
        else if (strcmp(argv[1], HELP)   == 0) help_mode();
        else                                   command_error();
    }
    else if (argc == ONE_ARG) run_solver();
    else command_error();
}


void help_mode()
{
    PRINTF_YELLOW("Чтобы запустить автоматическую проверку напишите: ./square test\n");
    PRINTF_YELLOW("Чтобы запустить ручную проверку напишите: ./square solver\nИли: ./square\n");
    PRINTF_YELLOW("Чтобы запустить автоматическую проверку напишите: ./square test\n");

}


void command_error()
{
    PRINTF_RED("Ошибка ввода в командной строке. Введите команду еще раз (./square help - помощь)\n");
}