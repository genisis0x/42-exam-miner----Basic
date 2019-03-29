#include <unistd.h>

void print(int i, unsigned char *octet)
{
	if (i)
	{
		print( i / 2, octet);
		(*octet & i) ? write(1, "1", 1) : write(1, "0", 1);
	}
}

void	print_bits(unsigned char octet)
{
	int i = 128;
	print(i, &octet);
}

/*int main (void)
{
	print_bits(2);
	return(0);
}*/
