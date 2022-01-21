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

typedef struct s_storylst
{
	char				*str;
	struct s_storylst	*next;
}	t_storylst;

typedef struct s_envp
{
	size_t			order;
	char			*var;
	char			*val;
	struct s_envp	*next;
}	t_envp;

typedef struct s_v
{
	int			ac;
	char		**av;
	t_envp		*envp;
	t_storylst	*storylst;
	pid_t		main_pid;
}	t_v;

t_v	g_v;

/*	>>>>>>>>>>>>>>>>>>>	прототипы функций libft	<<<<<<<<<<<<<<<<<<<<<<<<<	*/
size_t	ft_lstsize(t_list **lst);
size_t	ft_strlen(const char *str);
size_t	ft_len_array(char **array);
size_t	ft_strchr_count(const char *str, char c);
size_t	ft_strcpy(char *str_out, const char *str_in);
t_list	*ft_lstnew(char *str);
t_list	*ft_lstlast(t_list *lst);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_realloc(void **src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(char *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
char	*get_next_line(int fd, int buf_size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_lstclear(t_list **lst_step);
int		ft_atoi(const char *str);
/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/


/*	>>>>>>>>>>>>>>>>>>	прототипы функций builtins	<<<<<<<<<<<<<<<<<<<<<<<	*/
t_envp	*ft_lstlast_envp(t_envp *lst);
t_envp	*ft_lstnew_envp(char *str);
void	ft_lstadd_back_envp(t_envp **lst, t_envp *new);
int		ft_isalpha(int c);
char	*get_envp_val_name(char *full, int status);
int		dup_envp_to_list(char **envp);

int		builtins_handler(char **handle_me);
char	*b_pwd(int status);
int		b_env(char **av);
int		b_cd(char *dest);
int		b_echo(char **av);
void	b_exit(char **av);
int		b_unset(char **av);
int		b_export(char **av);
/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/

/*	>>>>>>>>>>>>>>>>>>	 прототипы функций Вагиза	<<<<<<<<<<<<<<<<<<<<<<<	*/
void	ft_catch_sign(void);
void	ft_pip_exe_fork(char *str);
char	**ft_split_av(const char *str);
int		ft_remove_cov(char **str);
/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/

#endif
