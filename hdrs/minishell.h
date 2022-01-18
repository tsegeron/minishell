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
typedef struct s_list
{
	char *str;
	struct	s_list	*next;
}	t_list;
typedef struct s_v
{
	int		ac;
	char	**av;
	char	**envp;
	t_list	*storylst;
}	t_v;
t_v	g_v;

size_t	ft_strlen(const char *str);
size_t	ft_strcpy(char *str_out, const char *str_in);
size_t	ft_len_array(char **array);
char	*ft_strdup(const char *str);
int		ft_init_envp_gv(char **envp);
char	*get_next_line(int fd, int buf_size);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstclear(t_list **lst_step);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_lstsize(t_list **lst);
t_list	*ft_lstnew(char *str);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(const char *str, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strchr_count(const char *str, char c);
void	ft_pip_exe_fork(void);
#endif
