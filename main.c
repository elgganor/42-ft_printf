#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int *p;

	ft_printf("%p\n", p);
	printf("%p\n", p);
	return (0);
}