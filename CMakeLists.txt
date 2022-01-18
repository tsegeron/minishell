cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c hdrs/minishell.h srcs/libfts/ft_strlen.c srcs/libfts/ft_strcpy.c
        srcs/libfts/ft_lstadd_back.c srcs/libfts/ft_lstclear.c srcs/libfts/ft_lstnew.c
        srcs/libfts/ft_lstlast.c srcs/libfts/ft_lstsize.c srcs/libfts/ft_calloc.c srcs/builtins/env.c
        srcs/libfts/get_next_line.c srcs/libfts/ft_bzero.c srcs/libfts/ft_strchr.c srcs/libfts/ft_strdup.c
        srcs/libfts/ft_strjoin.c srcs/libfts/ft_split.c srcs/libfts/ft_substr.c srcs/ft_pip_exe_fork.c srcs/libfts/ft_strchr_count.c)
