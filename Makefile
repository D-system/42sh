##
## Makefile for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
##
## Made by aymeric derazey
## Login   <deraze_a@epitech.net>
##
## Started on  Fri May 30 00:29:56 2008 aymeric derazey
## Last update Fri May 30 02:18:30 2008 thomas brennetot
##


NAME		=	42sh

SRC_SH		=	main.c				\
			get_env.c			\
			loop.c				\
			gere_keyboard.c			\
			gere_key.c			\
			history.c			\
			command.c			\
			get_history.c			\
			exec.c				\
			my_access.c			\
			path_to_tab.c			\
			parse_str.c			\
			put_zero.c			\
			status.c			\
			cdnarn.c

SRC_GERE	=	./gere/gere.c			\
			./gere/gere_redirect.c		\
			./gere/gere_delimitor.c		\
			./gere/gere_dotcoma.c		\
			./gere/gere_left.c		\
			./gere/gere_pipe.c		\
			./gere/gere_right.c		\
			./gere/gere_or.c		\
			./gere/gere_and.c		\
			./gere/gere_double_left.c	\
			./gere/gere_double_right.c	\
			./gere/gere_bracket.c



SRC_INIT	=	./init/get_user.c		\
			./init/get_gid.c		\
			./init/get_uid.c		\
			./init/get_group.c		\
			./init/get_term_version.c	\
			./init/get_local.c		\
			./init/init.c			\
			./init/get_cfg.c

SRC_BUI		=	./builtins/builtins.c		\
			./builtins/my_alias.c		\
			./builtins/my_cd.c		\
			./builtins/my_env.c		\
			./builtins/my_exit.c		\
			./builtins/my_echo.c		\
			./builtins/my_setenv.c		\
			./builtins/my_unsetenv.c	\
			./builtins/my_set.c		\
			./builtins/add_local.c		\
			./builtins/check_syntax.c	\
			./builtins/cut_to_equal.c	\
			./builtins/update_local.c	\
			./builtins/up_check_syntax.c	\
			./builtins/set_prompt.c		\
			./builtins/set_history.c	\
			./builtins/cpy_old_local.c

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
			./lib/fetch_env_int.c		\
			./lib/get_next_line.c		\
			./lib/int_to_str.c		\
			./lib/my_memcpy.c		\
			./lib/my_pwd.c

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
			$(SRC_BUI)			\
			$(SRC_LOCAL)			\
			$(SRC_INIT)			\
			$(SRC_GERE)


INCLUDES	=	./include

OBJ_ALL		=	$(SRC_ALL:.c=.o)

CFLAGS		+=	-W -Wall -pedantic -ansi -D${OSTYPE} -I$(INCLUDES) -ggdb

CC_FreeBSD	=	gcc
CC_solaris	=	/usr/sfw/bin/gcc
CC_linux	=	gcc
CC		=	$(CC_${OSTYPE})

LIB_FreeBSD	=	-lefence -L/usr/local/lib/
LIB_solaris	=
LIB_linux	=	-lefence -L/usr/lib/
#LIB		=	$(LIB_${OSTYPE})

$(NAME)		:	$(OBJ_ALL)
			$(CC) -o $(NAME) $(OBJ_ALL) $(CFLAGS) $(LIB)

all		:	$(NAME)

etags		:
			@echo [TAGS ...]
			@etags $(SRC_ALL) $(INCLUDES)
			@echo [... DONE]

grep		:
			grep -H -n -e "int_to_str" $(SRC_ALL)

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