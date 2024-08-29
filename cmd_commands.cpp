/*!
 * \file
 * \brief Функции для обработки аргументов командной строки (описание).
 */


#include <stdio.h>
#include <string.h>

#include "cmd_commands.h"
#include "errors.h"
#include "tester.h"
#include "solver.h"
#include "utils.h"


ProgramStatus run_programm(int argc, const char *argv[])
{
    if (argc == 2)
    {
        if      (strcmp(argv[1], TEST)   == 0) return run_all_tests();
        else if (strcmp(argv[1], SOLVER) == 0) return run_solver();
        else if (strcmp(argv[1], HELP)   == 0) return help_mode();
        else                                   return command_error();
    }
    else if (argc == 1) return run_solver();
    else                      return command_error();
}


ProgramStatus help_mode()
{
    PRINTF_YELLOW("Чтобы запустить автоматическую проверку напишите: ./square --test\n");
    PRINTF_YELLOW("Чтобы запустить ручную проверку напишите: ./square --solver\nИли: ./square\n");
    return OK;
}


ProgramStatus command_error()
{
    return ERROR_COMAND;
}
