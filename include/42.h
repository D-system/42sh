/*
** 42.h for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/lib
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Tue May 27 18:35:13 2008 aymeric derazey
** Last update Thu May 29 18:39:14 2008 laurent lefebvre
*/

#ifndef __42_H__
# define __42_H__

# include <stdlib.h>
# include "42_struct.h"
# include "my_term.h"
# include "my_printf.h"

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

typedef	unsigned int	uint;
typedef	unsigned char	uchar;

/* INIT */
int		init(char **environ, t_info *info);
int		get_env(char **environ, t_info *info);
int		get_cfg(t_info *info);
int		set_default_var(t_info *info);
char		**path_to_tab(char *str);
int		get_local(t_info *info);


/* LOOP */
void		loop(t_info *info);

/* PARSEUR */
int		parse_str(t_info *info, char *str);

/* COMPLETION */
char		*completion(t_info *info);

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
int		set_alias(t_info *info, char **tab);
int		my_cd(t_info *info, char **tab);
int		my_env(t_info *info, char **tab);
int		my_exit(t_info *info, char **tab);
int		my_echo(t_info *info, char **tab);
int		my_setenv(t_info *info, char **tab);
int		my_unsetenv(t_info *info, char **tab);
int		my_set(t_info *info, char **tab);
int		add_local(t_info *info, char **tab);
char		**cpy_old_local(t_info *info, char **tab);
int		aff_local(t_info *info);
char		*add_local_concat(char *str);
char		*replace_char(char *str, char c);
int		check_syntax(t_info *info, char **tab);
int		check_begin(t_info *info, char *str);
int		check_equal(t_info *info, char *tab);
int		set_prompt(t_info *info, char **tab);
int		set_history(t_info *info, char **tab);

/* LOCAL VAR */
int		get_user(t_info *info);
void		get_uid(t_info *info);
void		get_gid(t_info *info);
void		get_history(t_info *info);
int		get_group(t_info *info);
int		get_size();

/* COMMAND */
int		command();

/* EXEC */
int		exec(t_info *info, char *str, int flag);
int		my_access(t_info *info, char **tab);

/* LIB */
int		my_getnbr(char *str);
int		my_getnbr_base(char *str, char *base);
void		*my_memset(void *b, int c, uint size);
void		my_put_nbr(int n);
void		put_nbr_fd(int n, int fd);
int		my_putchar(char c);
int		my_putstr(char *str);
char		*my_pwd(void);
char		**my_str_to_wordtab(char *str);
char		**my_str_to_wordtab_mode(char *src, char *delim);
int		my_strcmp(char *s1, char *s2);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strdup(char *str);
int		my_strlen(char *str);
int		my_strncmp(char *s1, char *s2, int n);
char		*my_strcat(char *s1, char *s2);
char		*my_strcat_trois(char *s1, char *s2, char *s3);
char		*epurstr(char *str);
void		free_tab(char **tab);
char		*fetch_env(char **env, char *str, char *sepa);
char		*get_next_line(const int fd);
int		my_putnbr_base(int n, char *base);
int		my_getnbr_base(char *str, char* base);
void		*my_memcpy(void *dest, void *src, int size);
int		int_len(int nb);
char		*int_to_str(int nb);


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
int		xchdir(const char *path);


/* OtherZ */
int		put_zero(char *str, char *delim);
int		status(t_info *info, int status);

#endif /* !__42_H__ */
