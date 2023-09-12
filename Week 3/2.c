#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 5 * x - 1);
}

float g(float x)
{
    return ((x * x * x + 1) / 5);
}

int main()
{
    float x0, error;
    int flag = 0, it = 0;

    do
    {
        printf("Enter the initial guess (x0): ");
        scanf("%f", &x0);

        if (fabs(g(x0) - x0) < 1)
        {
            flag = 1;
        }
        else
        {
            printf("This Method May Fail. Please choose a different initial guess.\n");
        }
    } while (flag != 1);

    printf("Enter the allowed error: ");
    scanf("%f", &error);

    do
    {
        it++;
        float x = g(x0);

        printf("%d iteration, value of x is %f, value of f(%f) is %f\n", it, x, x, f(x));

        if (fabs(x - x0) <= error)
        {
            flag = 0;
            printf("The root of the equation is approximately %f after %d iterations\n", x, it);
        }
        else
        {
            x0 = x;
        }
    } while (flag != 0);

    return 0;
}
