#include <stdio.h>
#include <assert.h>
#include "major.h"

//void print_test_result(CheckTest checker, int test_number);

const SquareEquation TESTS[] = {
    {0, 0, 0, 0, 0, INF_ROOTS}, 
    {1, 3, 2, -1, -2, TWO_ROOTS}, 
    {0, 7, 0, 0, 0, ONE_ROOTS}, 
    {1, 1, 1, 0, 0, ZERO_ROOTS},
    {0, 7, 0, 5, 5, TWO_ROOTS},
    {7, 0, 7, 0, 0, ZERO_ROOTS}
};

void print_test_result(const SquareEquation* expected, double t_x1, double t_x2, RootsNumber t_roots_num, int test_number, CheckTest checker)
{
    assert(expected);

    if (checker) printf("Test %d - OK\n", test_number + 1);
    else
    {
        printf("Test %d - ERROR\nError test: x1 = %lg, x2 = %lg, nRoots = %d\n"
           "Expected: x1 = %lg, x2 = %lg, nRoots = %d\n", 
           test_number, t_x1, t_x2, t_roots_num, expected->x1, expected->x2, expected->roots_num);
    }

}

CheckTest run_test(const SquareEquation* expected, double* t_x1, double* t_x2, RootsNumber* t_roots_num)
{
    assert(expected);
    assert(t_x1);
    assert(t_x2);
    assert(t_roots_num);

    SquareEquation test = {expected->a, expected->b, expected->c, 0, 0};
    solve_square(&test);

    bool check_x1 = is_equally(test.x1, expected->x1);
    bool check_x2 = is_equally(test.x2, expected->x2);
    bool check_roots_num = is_equally(test.roots_num, expected->roots_num);

    *t_x1 = test.x1;
    *t_x2 = test.x2;
    *t_roots_num = test.roots_num;

    if (check_x1 && check_x2 && check_roots_num) return TEST_OK;
    else
    {
        //error_test(expected, test.x1, test.x2, test.roots_num);
        return TEST_ERROR;
    }
}

void run_all_tests()
{
    int quantity_tests = sizeof(TESTS) / sizeof(SquareEquation);

    for (int test_number = 0; test_number < quantity_tests; test_number++)
    {
        double t_x1 = 0;
        double t_x2 = 0;

        RootsNumber t_roots_num = ZERO_ROOTS;

        const SquareEquation* test_i = &(TESTS[test_number]);
        CheckTest checker = run_test(test_i, &t_x1, &t_x2, &t_roots_num);
        print_test_result(test_i, t_x1, t_x2, t_roots_num, test_number, checker);

    }
}
