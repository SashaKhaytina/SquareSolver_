#include <stdio.h>
#include<math.h>

int main()
{
    // ax^2 + bx + c = 0
    double a, b, c;
    double disc;
    printf("Введите коэффициент при x^2, коэффициент при x, свободный коэффициент через пробел:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    printf("(%lf)x^2 + (%lf)x + (%lf) = 0\n\n", a, b, c);

    if (a == 0){
        double x = (-1)*c/b;
        printf("Единственный корень: %lf\n", x);
        }

    else{

        disc = b * b - 4 * a * c;
        // printf("%lf\n", disc);
        if (disc < 0){printf("Действительных корней нет\n");}
        else{
            double x1, x2;
            x1 = ((-1)*b + sqrt(disc))/(2*a);
            x2 = ((-1)*b - sqrt(disc))/(2*a);
            printf("Первый корень: %.2f\nВторой корень: %.2f\n", x1, x2);
            }
    }
    // printf("Введите коэффициент при x:");
    // printf("Введите свободный коэффициент:");

}
