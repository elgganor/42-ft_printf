#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("p: %.*d\n", -10, 0);
	ft_printf("f: %.*d\n", -10, 0);
	
	printf("p: %*.*d\n", 0, -5, 0);
	ft_printf("f: %*.*d\n", 0, -5, 0);

	printf("p: %*.*d\n", 5, 0, 0);
	ft_printf("f: %*.*d\n", 5, 0, 0);

	printf("p: %*.*d\n", -5, 0, 0);
	ft_printf("f: %*.*d\n", -5, 0, 0);

	return (0);
}