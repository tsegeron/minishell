CC			=	gcc
#-Wall -Wextra -Werror
FLAGS		=
#FLAGS_MLX	=	-framework OpenGL -framework AppKit
OPTFLAGS	=	-O2
#BON_FLG0	=	-D BONUS=0
#BON_FLG1	=	-D BONUS=1

RM			=	rm -rf
AR			=	ar rcs

# ------------------------------------------------------------------------------

NAME 	=	minishell
LIB		=	minishell.a
#LIB1	=	libft.a
#LIB2	=	pipex.a

HDRS	=	minishell.h
#HDRS_B	=	so_long_b.h

FLDR_S	=	srcs/
#FLDR_B	=	srcs_b/
FLDR_H	=	hdrs/

MAIN	=	main.c
#MAIN_B	=	checker.c

SRCS	=	libfts/ft_strdup.c libfts/ft_strlen.c libfts/ft_strcpy.c builtins/env.c \
			libfts/get_next_line.c libfts/ft_strchr.c libfts/ft_strjoin.c libfts/ft_lstadd_back.c \
			libfts/ft_lstclear.c libfts/ft_lstlast.c libfts/ft_lstnew.c libfts/ft_lstsize.c libfts/ft_calloc.c \
			libfts/ft_bzero.c libfts/ft_split.c libfts/ft_substr.c ft_pip_exe_fork.c libfts/ft_strchr_count.c



SRC		=	$(addprefix ${FLDR_S},${SRCS})
#SRCB	=	$(addprefix ${FLDR_B},${SRCS})
HDR		=	$(addprefix ${FLDR_H},${HDRS})
#HDR_B	=	$(addprefix ${FLDR_H},${HDRS_B})
OBJS	=	${SRC:%.c=%.o}
#OBJS_B	=	${SRCB:%.c=%.o}

# ------------------------------------------------------------------------------

READY	=	Minishell is ready
#READYB	=	Checker is ready
SWEPT	=	Directory was cleaned
_GREEN	=	\e[32m
_YELLOW	=	\e[33m
_CYAN	=	\e[36m
_END	=	\e[0m

# ------------------------------------------------------------------------------

#%.o:		${SRCS} ${HDRS}
#			@${CC} ${FLAGS} -c $< -o $@
%.o:		%.c	${HDR}
			@${CC} ${FLAGS} ${OPTFLAGS} -c -o $@ $<


${NAME}: 	${OBJS} ${MAIN}
			@${AR} ${LIB} $?
#			@${MAKE} clean
			@${CC} ${FLAGS} ${OPTFLAGS} -lreadline ${MAIN} ${LIB} -o ${NAME}
			@printf "${_GREEN}${READY}${_END}\n"


all:		${NAME}

clean:
			@${RM} ${OBJS}
			@printf "${_YELLOW}${SWEPT}${_END}\n"

fclean:		clean
			@${RM} ${NAME} ${LIB}

re:			fclean all

bonus:		${OBJS}
#			@${CC} ${FLAGS} ${OPTFLAGS} ${MAIN_B} ${LIB} -o ${NAME_B}
			@printf "${_GREEN}${READYB}${_END}\n"


#main:
#			@${CC} ${FLAGS} ${OPTFLAGS} main.c ${LIB}

#test:
#			@${CC} ${FLAGS} ${OPTFLAGS} test.c ${LIB}

norm:
			@norminette ${MAIN} ${FLDR_H} ${FLDR_S}


#exec:		${SRCS}
#			${CC} ${FLAGS} ${OPTFLAGS} ${SRCS} -o ${ENAME}


# ------------------------------------------------------------------------------

#check:		re


# ------------------------------------------------------------------------------

.PHONY: re all clean fclean bonus
