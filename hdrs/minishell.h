#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# define CLOSE "\001\033[0m"                 // Закрыть все свойства
# define BLOD  "\001\033[1m"                 // Подчеркнуть, жирным шрифтом, выделить
# define BEGIN(x,y) "\001\033["#x";"#y"m\002"    // x: background, y: foreground
typedef struct s_storylst
{
	char *str;
	struct	s_storylst	*next;
}	t_storylst;
typedef struct s_v
{
	int		ac;
	char	**av;
	char	**envp;
	t_storylst *storylst;
}	t_v;
t_v	g_v;

size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *str_out, const char *str_in);
size_t	ft_len_array(char **array);
char	*ft_strdup(const char *str);
int		ft_init_envp_gv(char **envp);
#endif
