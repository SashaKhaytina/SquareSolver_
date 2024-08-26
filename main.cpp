/*!
 * \file
 * \brief Главный файл, запускающий программу.
 */


#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "cmd_commands.h"
#include "tester.h"
#include "solver.h"
#include "utils.h"
#include "errors.h"


/*! \brief Функция, которая запускает программу.
 * 
 *  \param[in] argc - количество аргументов командной строки
 *  \param[in] argv - массив строк размером argc, в котором лежат аргументы командной строки.
 *  \see run_programm(int argc, const char *argv[])
 */
int main(int argc, const char *argv[])
{
    // ax^2 + bx + c = 0
    ProgramStatus status = OK;

    status = run_programm(argc, argv);

    print_error_code(status);
}
