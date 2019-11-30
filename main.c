#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main()
{
	printf("%p\n", (void *)-4525);
	ft_printf("%p\n", (void *)-4525);

	return (0);
}