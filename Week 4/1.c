//Allowed Error - 0.0001

#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 5 * x + 1);
}

int main()
{
    float x2,x1, error;
    int flag = 0, it = 0;
    do
    {
        printf("Enter the value of x0 : ");
        scanf("%f", &x2);
        printf("Enter the value of x1 : ");
        scanf("%f", &x1);
        if (f(x2)*f(x1)<0)
        {
            flag = 1;
        }
        else
        {
            printf("Wrong Intervals Try Again \n");
        }
    } while (flag != 1);
    printf("Enter The Allowed Error : ");
    scanf("%f", &error);

    do
    {
        it++;
        float x0 = x2-((x2-x1)/(f(x2)-f(x1))*f(x2));

        printf("%d iteration, value of x is %f value of f(%f) is %f\n", it, x0, x0, f(x0));
        if ((fabs(f(x0))) <= error)
        {
            flag = 0;
            printf("The root of the equation is %f after %d iteration\n", x0, it);
        }
        else
        {
            x1=x2;
            x2=x0;
        }
    } while (flag != 0);
    return 0;
}