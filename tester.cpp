#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

#include "major.h"
#include "solver.h"
#include "tester.h"
#include "colors.h"
#include "utils.h"


static void print_test_result(SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker);
static CheckTest run_test(SquareEquation* expected, SquareEquation* test);


static void print_test_result(SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker)
{
    assert(expected);
    assert(test);

    if (checker) GREEN("Test %d - OK\n", test_number);
    else
    {
        RED("Test %d - ERROR\nError test: x1 = %lg, x2 = %lg, nRoots = %d\n"
           "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n", 
           test_number, test->x1, test->x2, test->roots_num, expected->x1, expected->x2, expected->roots_num);
    }

}

static CheckTest run_test(SquareEquation* expected, SquareEquation* test)
{
    assert(expected);
    assert(test);

    solve_square(test);

    bool check_x1 = is_equally(test->x1, expected->x1);
    bool check_x2 = is_equally(test->x2, expected->x2);
    bool check_roots_num = is_equally(test->roots_num, expected->roots_num);

    if (check_x1 && check_x2 && check_roots_num) 
        return TEST_OK;
    else 
        return TEST_ERROR;
}

ProgramStatus run_all_tests()
{
    // инициализация 
    FILE* file = NULL;
    if (open_file(&file) == ERROR_OPENING_FILE)
    {
        RED("Файл не удалось прочитать.\n");
        return ERROR_OPENING_FILE;
    }

    int counter = 0;
    double a = 0, b = 0, c = 0;
    double x1 = 0, x2 = 0;
    RootsNumber roots_num = ZERO_ROOTS;

    while (fscanf(file, "%lf %lf %lf %lf %lf %d", &a, &b, &c, &x1, &x2, (int*) &roots_num) != EOF)
    {

        SquareEquation test_ref = {a, b, c, x1, x2, roots_num}; // Образец
        SquareEquation test = {a, b, c}; // Проверка 

        CheckTest checker = run_test(&test_ref, &test);
        print_test_result(&test_ref, &test, counter + 1, checker);
        counter++;
    }
    fclose(file);
    return OK;
}