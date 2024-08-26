/*!
 * \file
 * \brief Файл, в котором реализуется автоматическая проверка (описание).
 * 
 * В данном файле собраны функции, которые нужны для автоматической проверки программы. Тесты лежат во внешнем файле "tests.txt"
 */


#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

#include "errors.h"
#include "solver.h"
#include "tester.h"
#include "utils.h"


static void print_test_result(const SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker);
static ProgramStatus run_test(const SquareEquation* expected, SquareEquation* test, CheckTest* checker);



static void print_test_result(const SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker)
{
    assert(expected);
    assert(test);


    if (checker)
    {
        PRINTF_GREEN("Test %d - OK\n", test_number);
    }
    else
    {
        PRINTF_RED("Test %d - ERROR\n"
            "Error test: x1 = %lg, x2 = %lg, nRoots = %d\n"
            "Expected:   x1 = %lg, x2 = %lg, nRoots = %d\n", 
            test_number, 
                test->x1,     test->x2,     test->roots_num, 
            expected->x1, expected->x2, expected->roots_num);
    }
}


static ProgramStatus run_test(const SquareEquation* expected, SquareEquation* test, CheckTest* checker)
{
    assert(expected);
    assert(test);

    ProgramStatus status = OK;

    status = type_solve(test);

    bool check_x1 =        are_equal(test->x1, expected->x1);
    bool check_x2 =        are_equal(test->x2, expected->x2);
    bool check_roots_num = are_equal(test->roots_num, expected->roots_num);

    if (check_x1 && check_x2 && check_roots_num) 
        *checker = TEST_OK;
    else 
        *checker = TEST_ERROR;

    return status;
}


ProgramStatus run_all_tests()
{
    FILE* file = NULL;
    if (open_file(&file, "tests.txt", "r") == ERROR_OPENING_FILE)
        return ERROR_OPENING_FILE;
    
    int counter = 1;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    RootsNumber roots_num = ZERO_ROOTS;

    ProgramStatus status = OK;

    while (fscanf(file, "%lf %lf %lf %lf %lf %d", 
                         &a, &b, &c, &x1, &x2, (int*) &roots_num) != EOF)
    {

        const SquareEquation test_ref = {a, b, c, x1, x2, roots_num}; // Образец
        SquareEquation test           = {a, b, c};                    // Проверка 

        CheckTest checker = TEST_OK;

        status = run_test(&test_ref, &test, &checker);

        print_test_result(&test_ref, &test, counter, checker);
        
        counter++;
    }
    if (fclose(file) != 0) status = ERROR_CLOSING_FILE;
    return status;
}