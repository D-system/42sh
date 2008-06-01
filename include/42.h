/*
** 42.h for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/include
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat May 31 00:36:54 2008 aymeric derazey
** Last update Sun Jun  1 06:52:16 2008 nicolas mondange
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
# define HERE 0
# define NOT_HERE 1

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
void		init(char **environ, t_info *info);
int		get_env(char **environ, t_info *info);
void		get_cfg(t_info *info);
int		set_default_var(t_info *info);
char		**path_to_tab(char *str);
int		get_local(t_info *info);
int		get_set(t_info *info);

/* LOOP */
void		loop(t_info *info);

/* PARSEUR */
int		parse_str(t_info *info, char *str);
int		parse_redir(char *str);
int		parse_pipe(char *buff);
int		pipe_space_pipe(char *buff);
int		check_sec_pipe(char *buff, int *i);
int		pipe_end(char *buff);
int		pipe_begin(char *buff);
int		parse_chevr_d(char *buff);
int		chevr_d_space_chevr_d(char *buff);
int		check_sec_chevr_d(char *buff, int *i);
int		chevr_d_end(char *buff);
int		chevr_d_begin(char *buff);
int		parse_chevr_g(char *buff);
int		chevr_g_space_chevr_g(char *buff);
int		check_sec_chevr_g(char *buff, int *i);
int		chevr_g_end(char *buff);
int		chevr_g_end(char *buff);
int		chevr_g_begin(char *buff);

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
void		give_event(t_info *params, char *to_fill, int limit);
int		my_cmp(char *line, char c);
void		my_word_str(char *str, char c);
void		read_line(t_event *new_elem, char *line);

/* PROMPT */
void		prompt(t_info *info);
int		launch_fct(t_info *info, int i, char *prompt);
void		full_hostname(t_info *info);
void		hostname_to_dot(t_info *info);
void		pourcent(t_info *info);
void		tild(t_info *info);
void		user_name(t_info *info);
void		last_status(t_info *info);

/* GERE_CLAV */

char		*gere_keyboard(t_info *info);
int		find_key(t_info *info, char *new, char *buff);
void		add_to_buff(char *buff, char *new);
int		my_compare(char *new);
int		do_action(t_info *info, int i, char *buff);
void		my_canonical(int i);
void		my_blank(char *str, t_info *info);
int		find_key(t_info *info, char *new, char *buff);
int		my_out_c(int c);
char		*xtgetstr(char *cap, char **area);
void		my_put_cursor(char *data);

/* GERE_KEY */

int		gere_key_enter(t_info *info, char *buff);
int		gere_key_up(t_info *info, char *buff);
int		gere_key_down(t_info *info, char *buff);
int		gere_key_right(t_info *info, char *buff);
int		gere_key_left(t_info *info, char *buff);
int		gere_key_back(t_info *info, char *buff);
int		gere_key_del(t_info *info, char *buff);

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
char		*cdnarn(char *str, char *str_delim, char *delim);

/* BUILTINS */
int		builtins(t_info *info, char *str);
int		set_alias(t_info *info, char **tab);
int		my_alias(t_info *info, char **tab, char *str);
int		my_cd(t_info *info, char **tab);
int		my_env(t_info *info, char **tab);
int		my_exit(t_info *info, char **tab);
int		my_echo(t_info *info, char **tab);
int		check_var(char *var, char **tab, char *delim);
int		my_setenv(t_info *info, char **tab);
int		my_unsetenv(t_info *info, char **tab);
int		my_set(t_info *info, char **tab);
int		my_unset(t_info *info, char **tab);
void		unsetall(t_info *info);
void		unset_just_that(char *str, t_info *info);
void		unset_free_n_renew(t_info *info, int delete_local);
int		add_local(t_info *info, char *str);
int		add_with_equal(t_info *info, char *str, char **new_local);
int		add_without_equal(t_info *info, char *str, char **new_local);
int		update_local(t_info *info, char *str, int fetched);
int		up_check_syntax(t_info *info, char *str, int fetched);
int		up_check_equal(t_info *info, char *str, int fetched);
int		update_with_equal(t_info *info, char *str, int fetched);
int		update_without_equal(t_info *info, char *str, int fetched);
char		*cut_to_equal(char *str, int count);
int		where_is_equal(char *str);
int		is_here(char *str, char c);
char		**cpy_old_local(t_info *info);
int		aff_local(t_info *info);
int		check_syntax(t_info *info, char *str, char **new_local);
int		check_begin(t_info *info, char *str);
int		check_equal(t_info *info, char *tab, char **new_local);
int		set_prompt(t_info *info);
int		set_history(t_info *info, char **tab);

/* LOCAL VAR */
int		get_user(t_info *info);
void		get_uid(t_info *info);
void		get_gid(t_info *info);
void		get_history(t_info *info);
int		get_group(t_info *info);
void		get_term_version(t_info *info);
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
char		**str_to_wordtab(char *src, char *delim);
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
int		fetch_env_int(char **env, char *str, char *sepa);
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
