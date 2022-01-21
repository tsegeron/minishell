cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c hdrs/minishell.h srcs/ft_strdup.c srcs/ft_strlen.c srcs/ft_strcpy.c srcs/ft_init.c srcs/builtins/cd.c srcs/builtins/echo.c srcs/builtins/builtins_handler.c srcs/builtins/exit.c srcs/builtins/export.c srcs/builtins/unset.c srcs/builtins/0.dup_envp_to_list.c srcs/builtins/0.utils.c)
