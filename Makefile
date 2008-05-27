##
## Makefile for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/official
## 
## Made by aymeric derazey
## Login   <deraze_a@epitech.net>
## 
## Started on  Mon Mar 31 16:44:23 2008 aymeric derazey
## Last update Tue May 27 18:35:40 2008 laurent lefebvre
##

NAME		=	42sh

SRC_SH		=	main.c				\
			init.c				\
			get_env.c			\
			get_user.c			\
			get_set.c			\
			get_gid.c			\
			get_uid.c			\
			get_pwd.c			\
			loop.c				\
			get_cfg.c			\
			gere.c				\
			gere_redirect.c			\
			gere_delimitor.c		\
			gere_dotcoma.c			\
			gere_left.c			\
			gere_pipe.c			\
			gere_right.c			\
			gere_or.c			\
			gere_and.c			\
			gere_double_left.c		\
			gere_double_right.c		\
			gere_bracket.c			\
			history.c			\
			command.c			\
			exec.c				\
			my_access.c			\
			path_to_tab.c			\
			parse_str.c			\
			put_zero.c			\
			status.c			\
			cut_delim_nextword_and_return_nextword.c

SRC_BUI		=	./builtins/builtins.c		\
			./builtins/my_cd.c		\
			./builtins/my_env.c		\
			./builtins/my_exit.c		\
			./builtins/my_echo.c		\
			./builtins/my_setenv.c		\
			./builtins/my_unsetenv.c	\
			./builtins/my_set.c		\
			./builtins/add_local.c		\
			./builtins/check_syntax.c	\
			./builtins/add_local_concat.c	\
			./builtins/set_prompt.c		\
			./builtins/set_history.c

SRC_LIB		=	./lib/my_getnbr.c		\
			./lib/my_getnbr_base.c		\
			./lib/my_putchar.c		\
			./lib/my_putstr.c		\
			./lib/my_put_nbr.c		\
			./lib/my_strlen.c		\
			./lib/my_strcat.c		\
			./lib/my_strcat_trois.c		\
			./lib/my_strcmp.c		\
			./lib/my_strncmp.c		\
			./lib/my_strcpy.c		\
			./lib/my_strncpy.c		\
			./lib/my_strdup.c		\
			./lib/put_nbr_fd.c		\
			./lib/my_putnbr_base.c		\
			./lib/my_memset.c		\
			./lib/epurstr.c			\
			./lib/my_str_to_wordtab.c	\
			./lib/my_str_to_wordtab_mode.c	\
			./lib/free_tab.c		\
			./lib/fetch_env.c		\
			./lib/get_next_line.c		\
			./lib/my_memcpy.c

SRC_ERR		=	./err/xmalloc.c			\
			./err/xopen.c			\
			./err/xwrite.c			\
			./err/xread.c			\
			./err/xfree.c			\
			./err/xwait.c			\
			./err/xpipe.c			\
			./err/xfork.c			\
			./err/xclose.c			\
			./err/xdup2.c			\
			./err/xchdir.c

SRC_PRT		=	./prompt/prompt.c		\
			./prompt/launch_fct.c		\
			./prompt/full_hostname.c	\
			./prompt/pourcent.c		\
			./prompt/tild.c			\
			./prompt/hostname_to_dot.c	\
			./prompt/user_name.c		\
			./prompt/last_status.c

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

SRC_COMPL	=	./completion/completion.c

SRC_ALL		=	$(SRC_SH)			\
			$(SRC_LIB)			\
			$(SRC_ERR)			\
			$(SRC_PRT)			\
			$(SRC_PTF)			\
			$(SRC_COMPL)			\
			$(SRC_BUI)


INCLUDES	=	42.h

OBJ_ALL		=	$(SRC_ALL:.c=.o)

CFLAGS		+=	-W -Wall -pedantic -ansi -D${OSTYPE} -I.

CC_FreeBSD	=	gcc
CC_solaris	=	/usr/sfw/bin/gcc
CC_linux	=	gcc
CC		=	$(CC_${OSTYPE})

LIB_FreeBSD	=	-lefence -L/usr/local/lib/
LIB_solaris	=
LIB_linux	=	-lefence -L/usr/lib/
LIB		=	$(LIB_${OSTYPE})

$(NAME)		:	$(OBJ_ALL)
			$(CC) -o $(NAME) $(OBJ_ALL) $(CFLAGS) $(LIB)

all		:	$(NAME)

etags		:
			@echo [TAGS ...]
			@etags $(SRC_ALL) $(INCLUDES)
			@echo [... DONE]

debug		:
			grep -H -n -e "debug" *.c */*.c

clean		:
			rm -f $(OBJ_ALL)
			find . \( -name "*.o" -o -name "*~" -o -name "#*#" \) -delete

c		:	clean

fclean		:	clean
			rm -rf $(NAME)

re		:	fclean all

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@

.PHONY		:	all clean fclean re etafs .c.o