#include "../hdrs/minishell.h"

char	*ft_strdup(const char *str)
{
	char	*str_in;
	char	*str_r;

	if (!str)
		return (NULL);
	str_in = (char *) str;
	str_r = (char *) malloc(ft_strlen(str_in) + 1);
	if (!str_r)
		return (NULL);
	ft_strcpy(str_r, str);
	return (str_r);
}