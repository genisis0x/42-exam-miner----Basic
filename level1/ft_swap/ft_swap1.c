//PASSED IN EXAM
void	ft_swap(int *a, int *b)
{
	*a ^= *b ^= *a ^= *b; // XOR operation using toggling method
}


// XOR of the element with the element gives 0;

// #include <stdio.h>
// int main()
// {
//     int a = 13;
//     int b = 12;
//     ft_swap(&a, &b);
//     printf("The value of a is %d && b is %d", a, b);
//     return 0;
// }

