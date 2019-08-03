void	ft_swap(int *a, int *b)
{
	*a ^= *b; // a = a xor b;
	*b ^= *a; // b = (a xor b xor b) or (a);
	*a ^= *b; // a = (a xor b xor a) or(b);
}


// XOR of the element with the element gives 0;

/*#include <stdio.h>
int main()
{
    int a = 12;
    int b = 13;
    ft_swap(&a, &b);
    printf("The value of a is %d && b is %d", a, b);
    return 0;
}*/

