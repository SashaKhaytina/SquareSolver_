#ifndef MAJOR_TESTER_H
#define MAJOR_TESTER_H

#include "status.h"

/*! Тип перечисление.
 * 
 *  Перечисление вариантов результатов обработки теста.
 */
enum CheckTest 
{
    TEST_ERROR,    /*!< Означает, что тест провален. */
    TEST_OK        /*!< Означает, что тест пройден верно. */
};

/*!
 * \brief Функция, которая запускает обработку всех тестов.
 * 
 * \return Возвращает успешность выполнения (ОК или какая-либо ошибка)
 * \see print_test_result(SquareEquation* expected, SquareEquation* test, int test_number, CheckTest checker)
 * \see run_test(SquareEquation* expected, SquareEquation* test)
 * \see open_file(&file)
 */
ProgramStatus run_all_tests();

#endif