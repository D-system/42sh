/*
** 42.h for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/official
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Mon Mar 31 17:18:10 2008 aymeric derazey
** Last update Thu May  8 18:14:06 2008 thomas brennetot
*/

#ifndef __42_H__
# define __42_H__

# include <stdlib.h>
# include "lib/my_printf/my_printf.h"

/* DEFINES */
# define BUFF_COMPL 2048 /* Taille de la ligne de commande (COMPL == completion) */
# define NO_REDIRECTION 2 /* gere_redirect */
# define NO_BUILTINS 24
# define FATHER 0
# define CHILD 1
# define EXIT_EXIT 42

# ifndef __EXIT_FAILURE__
#  define EXIT_FAILURE 1
# endif
# ifndef __EXIT_SUCCESS__
#  define EXIT_SUCCESS 0
# endif

# define printf my_printf
# define debug my_printf

/* STRUCT */

/* Struct list chaine pour l'historique */
typedef struct		s_event
{
  int			nbr;
  char			*time;
  char			*info;
  struct s_event	*next;
}			t_event;

/* structure principale */
typedef struct	s_info
{
  char		**env;
  char		**set;
  char		*prompt;
  char		**path;
  int		last_status; /* valeur de retour du wait */
  t_event	*history;
  int		nbr_cmd;
}		t_info;

/* structure pour xmalloc */
typedef struct	s_mal
{
  void		*addr;
  struct s_mal	*next;
}		t_mal;

/* structure pour gere_redirect */
typedef struct	s_gere
{
  char		*str;
  int		(*func)();
  int		size_str;
}		t_gere;

/* structure pour builtins */
typedef struct	s_bui
{
  char		*str;
  int		(*func)();
}		t_bui;

/* structure pour le builtin set */
typedef	struct	s_set
{
  char		*cmd;
  int		(*func)();
  int		len;
}		t_set;

/* structure pour le prompt */
typedef struct	s_prompt
{
  char		c;
  void		(*func)();
}		t_prompt;

/* INIT */
int		init(char **environ, t_info *info);
int		get_env(char **environ, t_info *info);
int		get_cfg(t_info *info);
int		set_default_var(t_info *info);
char		**path_to_tab(char *str);
int		get_set(t_info *info);

/* LOOP */
int		loop(t_info *info);

/* PARSEUR */
int		parse_str(t_info *info, char *str);

/* COMPLETION */
int		completion(t_info *info, char *str);

/* HISTORY */
void		load_event(t_info *params);
void		read_line(t_event *new_elem, char *line);
void		parse_event(t_info *params, char *line);
void		save_event(t_info *params);
t_event		*first_event(t_info *params, char *to_add, time_t *clock);
int		aff_event(t_info *params, char **tab);
void		clear_event(t_info *params, int nbr_elm, int limit);
t_event         *read_first_line(t_info *params, char *line);
void		add_event(t_info *params, char *to_ad);

/* PROMPT */
void		prompt(t_info *info);
int		launch_fct(t_info *info, int i);
void		full_hostname(t_info *info);
void		hostname_to_dot(t_info *info);
void		pourcent(t_info *info);
void		tild(t_info *info);
void		user_name(t_info *info);
void		last_status(t_info *info);

/* GERE_REDIRECT */
int		gere(t_info *info, char *str, int flag);
int		gere_redirect(t_info *info, char *str, int flag);
int		gere_delimitor(t_info *info, char *str, int flag);
int		gere_dotcoma(t_info *info, char *str, int flag);
int		gere_left(t_info *info, char *str, int flag);
int		gere_pipe(t_info *info, char *str, int flag);
int		gere_right(t_info *info, char *str, int flag);
int		gere_bracket(t_info *info, char *str, int flag);
int		gere_or(t_info *info, char *str, int flag);
int		gere_and(t_info *info, char *str, int flag);
int		gere_double_left(t_info *info, char *str, int flag);
int		gere_double_right(t_info *info, char *str, int flag);
char		*cut_delim_nextword_and_return_nextword(char *str, char *str_delim_nextword_less, char *delim);

/* BUILTINS */
int		builtins(t_info *info, char *str);
int		my_cd(t_info *info, char **tab);
int		my_env(t_info *info, char **tab);
int		my_exit(t_info *info, char **tab);
int		my_echo(t_info *info, char **tab);
int		my_setenv(t_info *info, char **tab);
int		my_unsetenv(t_info *info, char **tab);
int		my_set(t_info *info, char **tab);
int		aff_set(t_info *info);
int		set_prompt(t_info *info, char **tab);
int		set_history(t_info *info, char **tab);

/* COMMAND */
int		command();

/* EXEC */
int		exec(t_info *info, char *str, int flag);
int		my_access(t_info *info, char **tab);

/* LIB */
int		my_getnbr(char *str);
int		my_getnbr_base(char *str, char *base);
void		*my_memset(char *b, char c, int size);
void		my_put_nbr(int n);
void		put_nbr_fd(int n, int fd);
int		my_putchar(char c);
int		my_putstr(char *str);
char		*my_pwd(void);
char		**my_str_to_wordtab(char *str);
char		**my_str_to_wordtab_mode(char *src, char *delim);
int		my_strcmp(char *s1, char *s2);
char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *str);
int		my_strlen(char *str);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcat(char *s1, char *s2);
char		*epurstr(char *str);
void		free_tab(char **tab);
char		*fetch_env(char **env, char *str, char *sepa);
char		*get_next_line(const int fd);
int		my_putnbr_base(int n, char *base);
int		my_getnbr_base(char *str, char* base);
void		*my_memcpy(void *dest, void *src, int size);

/* ERR */
void		*xmalloc(int size);
void		*mem_add(int rw, void *to_mem);
void		my_put_in_list(t_mal **begin, void *add);
void		*x_malloc(int size);
int		xopen(char *file, int flags);
int		xread(int fd, char *buf, int size);
int		xwrite(int fd, char *str, int size);
void		xfree(void *ptr);
void		freeall(void);
int		xwait(int *status);
int		xfork(void);
int		xpipe(int *fildes);
int		xdup2(int old_fd, int new_fd);
int		xclose(int fd);
int		xwaitpid(int wait_pid, int *status, int options);

/* OtherZ */
int		put_zero(char *str, char *delim);
int		status(t_info *info, int status);

#endif /* !__42_H__ */



/* TERMCAPS */

#ifndef __MY_SELECT__
# define __MY_SELECT__

#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/termios.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUF_SIZE 4096

typedef	struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

t_list		*push(t_list *list, char *str);
void		show_list(t_list *list, int pos);

int		canonical_mode(int flag);
void		display(int ac, char **av);
void		reverse_video(t_list *list);
void		clear_win();
void		my_outc(int c);
int		inf_list(int pos, int ac);
int		get_keys1(char *buf, int r, int ac);

#endif
