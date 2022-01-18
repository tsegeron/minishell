#include "hdrs/minishell.h"

//static int	change_dir(int case_num)
//{
//
//	return (EXIT_SUCCESS);
//}
//
//int	cd(char *dest)
//{
//	if (!dest)
//		return (change_dir(0));
//	if (ft_strcmp(dest, "-"))
//		return (change_dir(1));
//	else
//	{
//
//	}
//	return (EXIT_SUCCESS);
//}

char	*get_getenv_val_of_(char *find_me)
{
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));
	if (ft_strcmp(find_me, ""))
		return (getenv(find_me));

}

int	fill_env()
{

}

int env()
{
	size_t	i;

	i = 0;
	while (g_v.envp[i])
		ft_putendl_fd(g_v.envp[i++], 1);
	return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
	char	*s;
//	cd(av[1]);


//	s = getenv("PATH");
//	printf("%s", s);
}
