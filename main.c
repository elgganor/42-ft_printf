#include <stdio.h>
#include "ft_printf.h"

int main()
{
	int m;
	int r;

	m = ft_printf("f1: %.0i", 0);
	ft_printf("\nm1: %d\n", m);
	r = printf("p1: %.0i", 0);
	printf("\nr1: %d\n", r);
	m = ft_printf("f2: %.0i", 4);
	ft_printf("\nm2: %d\n", m);
	r = printf("p2: %.0i", 4);
	printf("\nr2: %d\n", r);
	m = ft_printf("f3: %.0i", -4);
	ft_printf("\nm3: %d\n", m);
	r = printf("p3: %.0i", -4);
	printf("\nr3: %d\n", r);
	return (0);
}