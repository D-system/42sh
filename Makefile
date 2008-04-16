##
## Makefile for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/official
## 
## Made by aymeric derazey
## Login   <deraze_a@epitech.net>
## 
## Started on  Mon Mar 31 16:44:23 2008 aymeric derazey
## Last update Wed Apr 16 14:54:01 2008 thomas brennetot
##

NAME		=	42sh

SRC_SH		=	main.c				\
			init.c				\
			get_env.c			\
			loop.c				\
			gere_redirect.c			\
			gere_dotcoma.c			\
			gere_left.c			\
			gere_pipe.c			\
			gere_right.c			\
			command.c			\
			exec.c

SRC_LIB		=	./lib/my_getnbr.c		\
			./lib/my_getnbr_base.c		\
			./lib/my_putchar.c		\
			./lib/my_putstr.c		\
			./lib/my_put_nbr.c		\
			./lib/my_strlen.c		\
			./lib/my_strcat.c		\
			./lib/my_strcmp.c		\
			./lib/my_strncmp.c		\
			./lib/my_strcpy.c		\
			./lib/my_strncpy.c		\
			./lib/my_strdup.c		\
			./lib/my_putnbr_base.c		\
			./lib/my_memset.c		\
			./lib/epurstr.c			\
			./lib/free_tab.c		\
			./lib/fetch_env.c		\
			./lib/get_next_line.c

SRC_ERR		=	./err/xmalloc.c			\
			./err/xopen.c			\
			./err/xwrite.c			\
			./err/xread.c			\
			./err/xfree.c

SRC_PRT		=	./prompt/prompt.c		\
			./prompt/launch_fct.c		\
			./prompt/full_hostname.c	\
			./prompt/pourcent.c		\
			./prompt/tild.c			\
			./prompt/hostname_to_dot.c	\
			./prompt/user_name.c

SRC_PTF		=	./lib/my_printf/my_printf.c	\
			./lib/my_printf/my_c.c		\
			./lib/my_printf/my_d.c		\
			./lib/my_printf/my_modu.c	\
			./lib/my_printf/my_p_P.c	\
			./lib/my_printf/my_s.c		\
			./lib/my_printf/my_u.c		\
			./lib/my_printf/my_o_x_X.c	\
			./lib/my_printf/my_S.c		\
			./lib/my_printf/my_E.c


OBJ_SH		=	$(SRC_SH:.c=.o)
OBJ_LIB		=	$(SRC_LIB:.c=.o)
OBJ_ERR		=	$(SRC_ERR:.c=.o)
OBJ_PRT		=	$(SRC_PRT:.c=.o)
OBJ_PTF		=	$(SRC_PTF:.c=.o)

CFLAGS		+=	-W -Wall -pedantic -ansi -g -D${OSTYPE} -I.

CC_FreeBSD	=	gcc
CC_solaris	=	/usr/sfw/bin/gcc
CC_linux	=	gcc
CC		=	$(CC_${OSTYPE})

LIB_FreeBSD	=	-Lefence -l/usr/pkg/lib/
LIB_solaris	=
LIB_linux	=	-Lefence -l/usr/lib/
LIB		=	$(LIB_${OSTYPE})

$(NAME)		:	$(OBJ_SH) $(OBJ_LIB) $(OBJ_ERR) $(OBJ_PRT) $(OBJ_PTF)
			$(CC) -o $(NAME) $(OBJ_SH) $(OBJ_LIB) $(OBJ_ERR) $(OBJ_PRT) $(OBJ_PTF) $(CFLAGS)

all		:	$(NAME)

etags		:
			etags *.[ch] */*.[ch]

clean		:
			rm -f $(OBJ_SH)
			rm -f $(OBJ_LIB)
			rm -f $(OBJ_ERR)
			rm -f $(OBJ_PRT)
			rm -f *~
			rm -f */*~

c		:	clean

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all


.PHONY		:	all clean fclean re

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@