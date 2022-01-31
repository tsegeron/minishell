#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
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

//# define CLOSE "\001\033[0m"                 // Закрыть все свойства
//# define BLOD  "\001\033[1m"                 // Подчеркнуть, жирным шрифтом, выделить
//# define BEGIN(x,y) "\001\033["#x";"#y"m\002"    // x: background, y: foreground

//typedef struct s_list
//{
//	char *str;
//	struct	s_list	*next;
//}	t_list;

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
	char		**envp_for_exe;
	t_envp		*envp;
	pid_t		main_pid;
	int			ret_status;
	int			fd_in;
	int			fd_save;
	int			fd_out;
	int			fd_util;
	int			fd[2];
	int			path_stat;
	char		**split_path;
	char		**split_cmd;
	char		**envp_path;
}	t_v;

t_v	g_v;

/*	>>>>>>>>>>>>>>>>>>>	прототипы функций libft	<<<<<<<<<<<<<<<<<<<<<<<<<	*/
size_t	ft_strlen(const char *str);
size_t	ft_len_array(char **array);
size_t	ft_strchr_count(const char *str, char c);
size_t	ft_strcpy(char *str_out, const char *str_in);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_realloc(void **src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strchr(char *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
char	*get_next_line(int fd, int buf_size);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atoi(const char *str);
char	*ft_itoa_uns(unsigned int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(char *str, char c);
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

/*	>>>>>>>>>>>>>>>>>>>	 прототипы функций mseastar	<<<<<<<<<<<<<<<<<<<<<<<	*/
void	ft_pip_exe_fork(char *str);
int		ft_exe(char **split_path, char **split_cmd, char **envp);
int		ft_spliting_path(char ***split);
int		ft_spliting_cmd(char ***split_cmd, char *cmd);
void	ft_clear_arrray(char **array);
int		ft_open_fd(char *str, int status);
int		ft_keyb_in(char *str);
char	*ft_str_for_cmd(char **array, int *i);
void	ft_child(char **array, int *i);
void	ft_pipex(char **array);
void	ft_create_envp_exe(void);

/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/

/*	>>>>>>>>>>>>>>>>>>>	 прототипы функций gernesto	<<<<<<<<<<<<<<<<<<<<<<<	*/
char	*replace_dollar_signs(char *str);
void	remove_quotes_and_split(char *str);
char	*replace_dollar_signs(char *str);
void	do_mthfoocking_redir_shit(char *check_me, char c, size_t *index, int *r_s);
void	my_sigint(int signum);
void	my_sigint_proc(int signum);
void	my_sigquit(int signum);
int		eof_exit(void);
void	handle_signals(void);
void	handle_signals_in_proc(void);
/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/

#endif
