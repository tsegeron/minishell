cmake_minimum_required(VERSION 3.20)
project(minishell C)

set(CMAKE_C_STANDARD 99)

add_executable(minishell main.c hdrs/minishell.h srcs/ft_strdup.c srcs/ft_strlen.c srcs/ft_strcpy.c srcs/ft_init.c srcs/ft_lst.c)
