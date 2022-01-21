#include "../hdrs/minishell.h"

<<<<<<< HEAD

static int	ft_check_argv(void)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = -1;
	while (g_v.av[++i])
	{
		if (ft_strchr_count(g_v.av[i], '\\'))
			return (1);
		count += ft_strchr_count(g_v.av[i], '"');
	}
	if (count % 2)
=======
static int	ft_counter_words(const char *str)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] == ' ')
			index++;
		if (str[index] == '\"')
		{
			while (str[++index] != '\"')
				;
			count++;
			while (str[index] != ' ' && str[index] != '\0')
				index++;
		}
		else if (str[index] != ' ' && str[index] != '\0')
		{
			count++;
			while (str[index] != ' ' && str[index] != '\0')
			{
				if (str[index] == '\"')
					while (str[++index] != '\"')
						;
				index++;
			}
		}
	}
	return (count);
}

static int	ft_check_argv(const char *str)
{
	if (ft_strchr_count(str, '\\') || ft_strchr_count(str, '"') % 2)
>>>>>>> merge
		return (1);
	return (0);
}

<<<<<<< HEAD
void	ft_pip_exe_fork(void)
{
	if (ft_check_argv())
	{
		printf("Error one more \\ or \" is not both\n");
		return;
	}
	printf("OK\n");
=======
void	ft_pip_exe_fork(char *str)
{
	char **str_r;
	if (ft_check_argv(str))
		printf("Error one more \\ or \" is not both\n");
	else
	{
		printf("%d\n", ft_counter_words(str));
		str_r = ft_split_av(str);
		for (int i = 0;str_r[i];i++)
			printf("%s\n", str_r[i]);
		printf("OK\n");
	}
>>>>>>> merge
}