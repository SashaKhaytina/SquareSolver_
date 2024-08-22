#include <stdio.h>
#include <assert.h>
#include "major.h"
#include "solver.h"
#include "tester.h"

static void print_test_result(const SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker);
static CheckTest run_test(const SquareEquation* expected, SquareEquation* test);


const SquareEquation TESTS[] = {
    {0, 0, 0, 0, 0, INF_ROOTS}, 
    {1, 3, 2, -1, -2, TWO_ROOTS}, 
    {0, 7, 0, 0, 0, ONE_ROOTS}, 
    {1, 1, 1, 0, 0, ZERO_ROOTS},
    {0, 7, 0, 5, 5, TWO_ROOTS},
    {7, 0, 7, 0, 0, ZERO_ROOTS},
    {2, -7, 3, 3, 0.5, TWO_ROOTS},
    {1, -5, -1, 5.19258, -0.192582, TWO_ROOTS}
};

static void print_test_result(const SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker)
{
    assert(expected);

    if (checker) printf("Test %d - OK\n", test_number);
    else
    {
        printf("Test %d - ERROR\nError test: x1 = %lg, x2 = %lg, nRoots = %d\n"
           "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n", 
           test_number, test->x1, test->x2, test->roots_num, expected->x1, expected->x2, expected->roots_num);
    }

}

static CheckTest run_test(const SquareEquation* expected, SquareEquation* test)
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

void run_all_tests()
{
    int quantity_tests = sizeof(TESTS) / sizeof(SquareEquation);

    for (int test_number = 0; test_number < quantity_tests; test_number++)
    {
        const SquareEquation* test_i = &(TESTS[test_number]);
        SquareEquation test = {test_i->a, test_i->b, test_i->c, 0, 0, ZERO_ROOTS};

        CheckTest checker = run_test(test_i, &test);
        print_test_result(test_i, &test, test_number + 1, checker);

    }
}
