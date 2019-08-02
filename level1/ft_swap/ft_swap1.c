void	ft_swap(int *a, int *b)
{
	*a ^= *b;
        *b = *a^*b;
        *a ^= *b;
}

/*#include <stdio.h>
int main()
{
    int a = 12;
    int b = 13;
    ft_swap(&a, &b);
    printf("The value of a is %d && b is %d", a, b);
    return 0;
}*/

