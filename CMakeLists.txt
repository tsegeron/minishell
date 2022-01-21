cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

<<<<<<< HEAD
<<<<<<< HEAD
add_executable(minishell main.c hdrs/minishell.h srcs/libfts/ft_strlen.c srcs/libfts/ft_strcpy.c
        srcs/libfts/ft_lstadd_back.c srcs/libfts/ft_lstclear.c srcs/libfts/ft_lstnew.c
        srcs/libfts/ft_lstlast.c srcs/libfts/ft_lstsize.c srcs/libfts/ft_calloc.c srcs/builtins/env.c
        srcs/libfts/get_next_line.c srcs/libfts/ft_bzero.c srcs/libfts/ft_strchr.c srcs/libfts/ft_strdup.c
        srcs/libfts/ft_strjoin.c srcs/libfts/ft_split.c srcs/libfts/ft_substr.c srcs/ft_pip_exe_fork.c srcs/libfts/ft_strchr_count.c)
=======
add_executable(minishell main.c hdrs/minishell.h srcs/ft_strdup.c srcs/ft_strlen.c srcs/ft_strcpy.c srcs/ft_init.c srcs/builtins/cd.c srcs/builtins/echo.c srcs/builtins/builtins_handler.c srcs/builtins/exit.c srcs/builtins/export.c srcs/builtins/unset.c srcs/builtins/0.dup_envp_to_list.c srcs/builtins/0.utils.c)
>>>>>>> merge
=======
add_executable(minishell main.c
        srcs/builtins/cd.c srcs/builtins/echo.c
        srcs/builtins/builtins_handler.c srcs/builtins/exit.c
        srcs/builtins/export.c srcs/builtins/unset.c
        srcs/builtins/0.dup_envp_to_list.c srcs/builtins/0.utils.c
        srcs/libfts/ft_calloc.c srcs/builtins/env.c
        srcs/libfts/get_next_line.c srcs/libfts/ft_bzero.c srcs/libfts/ft_strchr.c srcs/libfts/ft_strdup.c
        srcs/libfts/ft_strjoin.c srcs/libfts/ft_split.c srcs/libfts/ft_substr.c srcs/ft_pip_exe_fork.c srcs/libfts/ft_strchr_count.c srcs/ft_catch_sign.c srcs/ft_split_av.c srcs/ft_split_av_utils.c
        )
>>>>>>> q
