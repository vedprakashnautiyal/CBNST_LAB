//Allowed Error - 0.0001

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 5 * x + 1);
}

float f_(float x)
{
    return (3 * x * x - 5);
}

int main()
{
    float x0, error;
    int flag = 0, it = 0;
    do
    {
        printf("Enter the value of x0 : ");
        scanf("%f", &x0);
        if (f_(x0) != 0)
        {
            flag = 1;
        }
        else
        {
            printf("This Method Will Fail \n");
        }
    } while (flag != 1);
    printf("Enter The Allowed Error : ");
    scanf("%f", &error);

    do
    {
        it++;
        float x = x0-(f(x0)/f_(x0));

        printf("%d iteration, value of x is %f value of f(%f) is %f\n", it, x, x, f(x));
        if ((fabs(f(x))) <= error)
        {
            flag = 0;
            printf("The root of the equation is %f after %d iteration\n", x, it);
        }
        else
        {
            x0=x;
        }
    } while (flag != 0);
    return 0;
}