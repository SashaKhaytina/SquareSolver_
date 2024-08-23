// doxygen and doxywisard
//man doxywizard

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#include "major.h"
#include "solver.h"
#include "io.h"
#include "tester.h"
#include "colors.h"



static void run_programm(int argc, const char *argv[]);
void help_mode();
void command_error();

// cdecl
int main(int argc, const char *argv[])
{
    // ax^2 + bx + c = 0
    /// какой то капец

    run_programm(argc, argv);
}

static void run_programm(int argc, const char *argv[])
{
    if (argc == TWO_ARG) 
    {
        if (strcmp(argv[1], TEST) == 0) run_all_tests();
        else if (strcmp(argv[1], SOLVER) == 0) run_solver();
        else if (strcmp(argv[1], HELP) == 0) help_mode();
        else command_error();
    }
    else if (argc == ONE_ARG) run_solver();
    else command_error();
}


void help_mode()
{
    YELLOW("Чтобы запустить автоматическую проверку напишите: ./square test\n");
    YELLOW("Чтобы запустить ручную проверку напишите: ./square solver\nИли: ./square\n");
    YELLOW("Чтобы запустить автоматическую проверку напишите: ./square test\n");

}


void command_error()
{
    RED("Ошибка ввода в командной строке. Введите команду еще раз (./square help - помощь)\n");
}