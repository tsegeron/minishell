#include "../hdrs//minishell.h"

void	ft_clear_arrray(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
