#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int *p;
	int i;

	i = printf("%.5d", -1);
	printf("\nprintf => %d\n", i);
	ft_printf("%.5d\n", -1);
	return (0);
}