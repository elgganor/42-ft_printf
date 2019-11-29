#include "../libft.h"

char *ft_strtoupper(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_islower(s[i]))
			s[i] = ft_toupper(s[i]);
		i++;
	}
	return (s);
}