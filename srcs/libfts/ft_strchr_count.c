#include "../../hdrs/minishell.h"

size_t	ft_strchr_count(const char *str, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	if (str)
	{
		i = -1;
		while (str[++i])
			if (str[i] == c)
				count++;
	}
	return (count);
}