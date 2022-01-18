#include "../hdrs/minishell.h"

/*	Функция инициализации массива указателей типа (char *) для парсинга envp SHELL с мака, в наш eBash;
 * 	Возвращет 0 в случае успеха и 1 в случае ошибки;
 */
int	ft_init_envp_gv(char **envp)
{
	size_t	len_array;
	size_t	i;

	len_array = ft_len_array(envp);
	if (!len_array)
	{
		perror("Envp error : \n");
		return (1);
	}
	g_v.envp = malloc(sizeof (char *) * len_array + 1);
	if (!g_v.envp)
	{
		perror("Malloc error : \n");
		return (1);
	}
	g_v.envp[len_array] = NULL;
	i = -1;
	while (envp[++i])
		g_v.envp[i] = ft_strdup(envp[i]);
	return (0);
}
