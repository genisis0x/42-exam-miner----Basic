// Better Time Complexity with the elementation of even number and Odd number.

#include <stdio.h>
#include <stdlib.h>

void fprime(int a)
{
    int flag = 0;
    if(a == 1)
    {
        printf("1");
        return;
    }
    while(a % 2 == 0)
    {
        if(flag > 0)
            printf("*");
        printf("2");
        a /= 2;
        flag ++;
    }
    for (int i = 3; i *i <= a; i+=2)
    {
        
        while(a % i == 0)
        {
            if(flag > 0)
                printf("*");
            a /= i;
            printf("%d", i);
            flag++;
        }
    }
    if(a > 2)
    {
        if(flag > 0)
            printf("*");
        printf("%d", a);
    }
}

int main(int ac, char **av)
{
    if(ac ==2)
    {
        fprime(atoi(av[1]));
    }
    printf("\n");
    return 0;
}
