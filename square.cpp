// output roots, solve_linear {} -0



#include <stdio.h>
#include <math.h>
#include <assert.h>

const double DELTA = 1e-7;

enum RootsNumber 
{
    INF,
    NULL_ANS,
    ONE_ANS,
    TWO_ANS
};

void solve_square(struct SquareEquation* equation);
void input_coeff(double* coeff, char symbol);
void output_roots(struct SquareEquation* equation);
bool is_null(double n);
bool is_equally(double a, double b);
void clear_buffer();
RootsNumber solve_linear(double k, double b, double* x1);  // kx + b = 0
void run_tests(); // Запуск тестов


struct SquareEquation 
{
    double a;
    double b;
    double c;
    double x1;
    double x2;
    RootsNumber roots_num;
};

const struct SquareEquation test_massiv_Square[] = {
    {0, 0, 0, 0, 0, INF}, 
    {1, 3, 2, -1, -2, TWO_ANS}, 
    {0, 7, 0, 0, 0, ONE_ANS}, 
    {1, 1, 1, 0, 0, NULL_ANS}
};


int main()
{
    // ax^2 + bx + c = 0

    run_tests();

    /*
    struct SquareEquation equation = {};

    input_coeff(&equation.a, 'a');
    input_coeff(&equation.b, 'b');
    input_coeff(&equation.c, 'c');

    solve_square(&equation);

    output_roots(&equation);
    */
    

    return 0;
}


void input_coeff(double* coeff, char symbol)
{
    assert(coeff);

    printf("Введите коэффициент %c\n%c = ", symbol, symbol);

    while (scanf("%lf", coeff) == 0) 
    {
        clear_buffer();
        printf("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
    }

}


void solve_square(struct SquareEquation* equation)
{
    assert(equation);
    // сравнение чисел с точкой!
    double a = equation->a;
    double b = equation->b;
    double c = equation->c;
    double* x1 = &equation->x1;

    if (is_null(a))
    {
        equation->roots_num = solve_linear(b, c, x1);
    }
    else
    {
        double disc = b * b - 4 * a *c;
        if (disc < 0) equation->roots_num = NULL_ANS;
        else if (is_null(disc))
        {
            *x1 = -b/(2*a);
            if (is_null(*x1)) *x1 = abs(*x1);
            equation->roots_num = ONE_ANS;
        }
        else
        {
            double* x2 = &equation->x2;
            double d_sqrt = sqrt(disc);
            *x1 = (-b + d_sqrt)/(2*a);
            *x2 = (-b - d_sqrt)/(2*a);
            equation->roots_num = TWO_ANS;
        }


    }
}


void output_roots(SquareEquation* equation)
{
    assert(equation);
    switch(equation->roots_num)
    {
    case NULL_ANS:
        printf("Корней нет\n");
        break;

    case ONE_ANS:
        printf("Один корень x = %lg\n", equation->x1);
        break;

    case TWO_ANS:
        printf("Два корня: x1 = %lg, x2 = %lg\n", equation->x1, equation->x2);
        break;

    case INF:
        printf("Корней бесконечное количество\n");
        break;

    default:
        printf("Что-то не то...");
    }
}


bool is_null(double n)
{
    if ((abs(n)) < DELTA) return true;
    return false;
}

bool is_equally(double a, double b)
{
    if (abs(a - b) < DELTA) return true;
    return false;
}


void clear_buffer()
{
    while (getchar() != '\n') continue;
}


RootsNumber solve_linear(double k, double b, double* x1)
{
    assert(x1);
    if (is_null(k))
    {
        if (is_null(b)) return INF;
        else return NULL_ANS;
    }
    else 
    {
        *x1 = -b/k;
        return ONE_ANS;
    }

}


void run_tests()
{
    for(int i = 0; i < 4; i++)
    {
        struct SquareEquation now_sq = test_massiv_Square[i];
        struct SquareEquation now_sq_copy = test_massiv_Square[i];

        solve_square(&now_sq_copy);
        if ((is_equally(now_sq_copy.x1, now_sq.x1)) && (is_equally(now_sq_copy.x2, now_sq.x2)) && (is_equally(now_sq_copy.roots_num, now_sq.roots_num))) printf("Тест прошел нориально\n");
        else
        {
            printf("ОШИБКА =(\n");
            if (is_equally(now_sq_copy.x1, now_sq.x1) == false) printf("X1\n");
            if(is_equally(now_sq_copy.x2, now_sq.x2) == false) printf("X2\n");
            if (is_equally(now_sq_copy.roots_num, now_sq.roots_num) == false) printf("roots_num\n");

        }
    }
}
