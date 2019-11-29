#include <stdio.h>
#include "ft_printf.h"

int main()
{
	//afficher 5
	ft_printf("f: %.*d\n", -10, 5);
	// ajouter 9 espaces à la fin
	ft_printf("f: %.-10d\n", 5);

	printf("p: %.*d\n", -10, 5);
	printf("p: %.-10d\n", 5);

	return (0);
}