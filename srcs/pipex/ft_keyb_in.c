#include "../../hdrs/minishell.h"

void	ft_keyb_in(int fd, char *str)
{
	char	*buffer;
	char	*str_break;

	buffer = ft_strdup("hor");
	str_break = ft_strdup(str);
	str_break = ft_strjoin(str_break, "\n");
	while (ft_strcmp(str_break, buffer))
	{
		if (buffer)
			free(buffer);
		buffer = get_next_line(0, 1);
		if (!buffer)
			break ;
		if (ft_strcmp(str_break, buffer))
			write(g_v.fd_util, buffer, ft_strlen(buffer));
	}
	free(buffer);
}
