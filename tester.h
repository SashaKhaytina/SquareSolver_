#ifndef MAJOR_TESTER_H
#define MAJOR_TESTER_H

#include "major.h"

enum CheckTest 
{
    TEST_ERROR,
    TEST_OK
};

ProgramStatus run_all_tests();

#endif