#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	// ft_printf("%.-10d\n", 42);


	printf("real1: %*d\n", -10, 42);
	ft_printf("mine1: %*d\n", -10, 42);

	printf("real2: %*d\n", -10, -42);
	ft_printf("mine2: %*d\n", -10, -42);

	printf("real3: %*d\n", -10, 0);
	ft_printf("mine3: %*d\n", -10, 0);

	printf("real4: %.-10d\n", 42);
	ft_printf("mine4: %.-10d\n", 42);

	printf("real5: %.-10d\n", -42);
	ft_printf("mine5: %.-10d\n", -42);

	printf("real6: %.-10d\n", 0);
	ft_printf("mine6: %.-10d\n", 0);
	return (0);
}