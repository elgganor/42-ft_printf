#include <stdio.h>
#include "ft_printf.h"

int main()
{
	ft_printf("%t\n");
	ft_printf("======\n");
	ft_printf("%d\n", 10);
	ft_printf("======\n");
	ft_printf("%i\n", 10);
	ft_printf("======\n");
	ft_printf("%%\n");
	ft_printf("======\n");
	ft_printf("% \n");
	ft_printf("======\n");
	ft_printf("%s\n", "hello");
	ft_printf("======\n");
	ft_printf("%c\n", 'e');
}