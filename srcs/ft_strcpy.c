#include "../hdrs/minishell.h"

size_t	ft_strcpy(char *str_out, const char *str_in)
{
	char	*str1;
	size_t	i;
	size_t	j;

	str1 = (char *)str_in;
	j = ft_strlen(str1);
	i = -1;
	while (str_in[++i])
		str_out[i] = str_in[i];
	str_out[i] = '\0';
	return (j);
}
