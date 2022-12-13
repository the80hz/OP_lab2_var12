/* Вычислить корень n-ой степени из натурального числа с заданной точностью eps>0,
 * используя итерационную формулу метода последовательных приближений Ньютона:
 * √(n&x)=a_(i+1)=1/n((n-1) a_i+x/(a_i^(n-1))), i = 0, 1, 2... .
 * В качестве начальной точки a0 взять число, равное среднему значению двух целых чисел:
 * первое - n-ая степень данного числа равна ближайшему целому, которое меньше заданному.
 * второе - n-ая степень данного числа равна ближайшему целому, которое больше заданного.
 */

#include <stdio.h>
#include <math.h>



int main()
{
    int n, x, a0, a1, i;
    double eps;

    printf("Enter a natural number x:");
    scanf("%d", &x);
    printf("Enter a natural number n:");
    scanf("%d", &n);
    printf("Enter the eps accuracy:");
    scanf("%lf", &eps);

    a0 = (int)pow(x, 1.0 / n);
    a1 = a0 + 1;
    a0 = (int)pow(a0, n);
    a1 = (int)pow(a1, n);
    a0 = (a0 + a1) / 2;

    for (i = 0; fabs(pow(a0, n) - x) > eps; i++)
    {
        a1 = 1.0 / n * ((n - 1) * a0 + x / pow(a0, n - 1));
        a0 = a1;
    }

    printf("The %dth degree root of %d is equal to %d\n", n, x, a1);
    printf("Number of iterations: %d\n", i);

    return 0;
}
