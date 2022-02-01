/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gernesto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:20:53 by gernesto          #+#    #+#             */
/*   Updated: 2022/02/01 15:20:58 by gernesto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define CYAN "\x1b[36m"
# define END "\x1b[0m"

typedef struct s_quotes
{
	size_t	i;
	size_t	j;
	size_t	del;
	int		s;
	int		r_s;
	char	*trim;
	char	*tmp;
	char	*tmp_s;
}	t_quotes;

typedef struct s_envp
{
	size_t			order;
	char			*var;
	char			*val;
	struct s_envp	*next;
}	t_envp;

typedef struct s_v
{
	char		**av;
	char		**envp_for_exe;
	t_envp		*envp;
	pid_t		main_pid;
	int			ret_status;
	int			fd_save;
	int			fd_out;
	int			fd[2];
	int			path_stat;
	int			pipe_stat;
	char		**split_path;
	char		**split_cmd;
}	t_v;

t_v	g_v;

/*	>>>>>>>>>>>>>>>>>>>	прототипы функций libft	<<<<<<<<<<<<<<<<<<<<<<<<<	*/
size_t	ft_strlen(const char *str);
size_t	ft_len_array(char **array);
size_t	ft_strcpy(char *str_out, const char *str_in);
void	ft_bzero(void *s, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(char *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *str, char c);
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
int		bultins_handler_main(void);
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
void	ft_clear_arrray(char **array);
int		ft_open_fd(char *str, int status);
int		ft_keyb_in(char *str);
int		ft_str_for_cmd(char **array, int *i);
void	ft_child(char **array, const int *i);
void	ft_pipex(char **array);
int		ft_create_envp_exe(void);
void	sign_here_doc(int i);
/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/

/*	>>>>>>>>>>>>>>>>>>>	 прототипы функций gernesto	<<<<<<<<<<<<<<<<<<<<<<<	*/
size_t	count_words(char *str);
int		replace_dollar(t_quotes *q, char c);
void	implement_index(size_t *i, int *j, char *str, char c);
void	pull_str_from_quotes(t_quotes *q, char c);

void	separate_pipe_if_needed(char **str);
void	check_for_invalid_pipes(void);

char	*replace_dollar_signs(char *str);
void	remove_quotes_and_split(char *str);
void	do_mthf_redir_shit(char *check_me, char c, size_t *index, int *r_s);
void	my_sigint(int signum);
void	my_sigint_proc(int signum);
void	my_sigquit(int signum);
void	handle_signals(void);
void	handle_signals_in_proc(void);
/*	^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	*/

#endif
