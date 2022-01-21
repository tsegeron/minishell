#include "../hdrs/minishell.h"

static char *ft_remove_str(char *str)
{
	int i;
	int j;
	size_t count;
	char *str_r;

	count = ft_strlen(str) - ft_strchr_count(str, '\"');
	str_r = malloc(count + 1);
	if (!str_r)
		return (NULL);
	str_r[count] = '\0';
	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] != '\"')
			str_r[j++] = str[i];
	free(str);
	return (str_r);
}

int	ft_remove_cov(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!str[i][0])
		{
			while (str[i])
			{
				free(str[i]);
				str[i++] = NULL;
			}
			return (0);
		}
		str[i] = ft_remove_str(str[i]);
		if (!str[i])
			return(1);
		i++;
	}
	return (0);
}
