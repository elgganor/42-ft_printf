#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	int i;

	i = ft_printf("f: %*.*d\n", 0, 0, 0);
	printf("f: %d\n", i);
	i = printf("p: %*.*d\n", 0, 0, 0);
	printf("p: %d\n", i);

	return (0);
}