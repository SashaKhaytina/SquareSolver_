#include <stdio.h>
#include<math.h>

#define DELTA 0.00001
#define INF -1

int solver(double a, double b, double c, double* x1, double* x2);  // Возвращает количество корней и корни

int main()
{
    // ax^2 + bx + c = 0
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;


    printf("Введите коэффициент при x^2, коэффициент при x, свободный коэффициент через пробел:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("(%lf)x^2 + (%lf)x + (%lf) = 0\n\n", a, b, c);

    switch(solver(a, b, c, &x1, &x2))
    {
        case 0:
            printf("Корней нет\n");
            break;

        case 1:
            printf("Один корень x = %lg\n", x1);
            break;

        case 2:
            printf("Два корня: x1 = %lg, x2 = %lg\n", x1, x2);
            break;
        case INF:
            printf("Корней бесконечное количество\n");
            break;

        default:
            printf("Что-то не то...");
    }


}




int solver(double a, double b, double c, double* x1, double* x2){
    int n = 0;

    // сравнение чисел с точкой!
    if ((abs(a) - 0) < DELTA){
        if ((abs(b) - 0) < DELTA){
            if ((abs(c) - 0) < DELTA) return -1;
            else return 0;
        }
        else{
            *x1 = -c/b;
            return 1;
        }
    }
    else{
        double disc = b * b - 4 * a *c;
        if (disc < 0) return 0;
        if ((disc - 0) < DELTA){
            *x1 = -b/(2*a);
            *x2 = -b/(2*a);
            return 1;
        }
        else{
            double d_sqrt = sqrt(disc);
            *x1 = (-b + d_sqrt)/(2*a);
            *x2 = (-b - d_sqrt)/(2*a);
            return 2;
        }


    }
}



