/*!
 * \file
 * \brief Функции для обработки аргументов командной строки.
 */


#ifndef CMD_COMMANDS_H
#define CMD_COMMANDS_H

#include <stdio.h>
#include <math.h>

#include "errors.h"


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
 * 
 * \return Возвращает переменную типа ProgramStatus, которая показывает успешность выполнения программы (ОК или какая-либо ошибка).
*/
ProgramStatus run_programm(int argc, const char *argv[]);


/*! \brief Функция, которая запускает режим помощи.
 * 
 *  Выводит список всех возможных команд и их описание.
 * 
 * \return Возвращает переменную типа ProgramStatus, которая показывает успешность выполнения программы (ОК или какая-либо ошибка).
 */
ProgramStatus help_mode();


/*! \brief Функция, которая выводит сообщение об ошибке ввода команды.
 *  
 *  \return Возвращает переменную типа ProgramStatus, которая показывает успешность выполнения программы (ОК или какая-либо ошибка).
*/
ProgramStatus command_error();

#endif