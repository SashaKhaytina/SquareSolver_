#include <stdio.h>
#include<math.h>

// #define DELTA 0.00001

const double DELTA = 1e-7;

enum RootsNumber {
    INF,
    NULL_ANS,
    ONE_ANS,
    TWO_ANS
};

RootsNumber solve_square(double a, double b, double c, double* x1, double* x2);
void input_coeff(double* coeff, char symbol);
void output(int n_answer, double* x1, double* x2);
bool is_null(double n);
void go_to_new_str();



struct SquareEquation {
    double a;
    double b;
    double c;
    double x1;
    double x2;
    //todo roots number
};


int main()
{
    // ax^2 + bx + c = 0


    struct my_square equation = {};

    input_coeff(&equation.a, 'a');
    input_coeff(&equation.b, 'b');
    input_coeff(&equation.c, 'c');

    int n_answer = solve(equation.a, equation.b, equation.c, &equation.x1, &equation.x2);

    output(n_answer, &equation.x1, &equation.x2);
}





void input_coeff(double* coeff, char symbol)
{

    printf("Введите коэффициент %c\n%c = ", symbol, symbol);


    int flag = scanf("%lf", coeff);
    while(flag == 0){
        go_to_new_str();
        printf("Ошибка. Введите коэффициент %c еще раз:\n", symbol);
        flag = scanf("%lf", coeff);

    }

}





RootsNumber solve(double a, double b, double c, double* x1, double* x2)
{
    // сравнение чисел с точкой!
    if (is_null(a)){
        if (is_null(b)){
            if (is_null(c)) return INF;
            else return NULL_ANS;
        }
        else{
            *x1 = -c/b;
            return ONE_ANS;
        }
    }
    else{
        double disc = b * b - 4 * a *c;
        if (disc < 0) return NULL_ANS;
        if ((disc - 0) < DELTA){
            *x1 = -b/(2*a);
            return ONE_ANS;
        }
        else{
            double d_sqrt = sqrt(disc);
            *x1 = (-b + d_sqrt)/(2*a);
            *x2 = (-b - d_sqrt)/(2*a);
            return TWO_ANS;
        }


    }
}





void output(int n_answer, double* x1, double* x2)
{
        switch(n_answer)
    {
        case NULL_ANS:
            printf("Корней нет\n");
            break;

        case ONE_ANS:
            printf("Один корень x = %lg\n", *x1);
            break;

        case TWO_ANS:
            printf("Два корня: x1 = %lg, x2 = %lg\n", *x1, *x2);
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





void go_to_new_str()
{
    while(getchar() != '\n') continue;
}
