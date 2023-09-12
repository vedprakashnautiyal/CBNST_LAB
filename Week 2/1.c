// Intervals - 0 1
// Allowed Error - 0.0001

#include <stdio.h>
#include <math.h>

float f (float x)
{
    return (x*x*x - 5* x +1);
}

int main()
{
    float x,x1,x2,error;
    int flag=0,it=0;
    do
    {
        printf("Enter the value of intervals x1 and x2 : ");
        scanf("%f%f",&x1,&x2);
        if(f(x1)*f(x2)<0)
        {
            flag=1;
            printf("Root Lies Between %f and %f\n",x1,x2);
        }
        else
        {
            printf("Root Lies Out Of The Given Intervals, Try Again !!!\n");
        }
    } while(flag!=1);
        {
            printf("Enter The Allowed Error : ");
            scanf ("%f",&error);
            do
            {
                it++;
                x=(x1+x2)/2;
                printf("%d iteration, value of x is %f value of f(%f) is %f\n",it,x,x,f (x) );
                if((fabs(f(x)))<error)
                {
                    flag=0;
                    printf("The root of the equation is %f after %d iteration\n",x,it);
                }
                else if(f(x)*f(x1)<0)
                {
                    x2=x;
                }
                else
                {
                    x1=x;
                }
            }
            while (flag!=0);
            return 0;
    }
}
