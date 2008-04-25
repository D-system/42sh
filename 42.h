/*
** 42.h for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/official
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Mon Mar 31 17:18:10 2008 aymeric derazey
** Last update Thu Apr 24 20:06:07 2008 aymeric derazey
*/

#ifndef __42_H__
# define __42_H__

#include "lib/my_printf/my_printf.h"

/* DEFINES */
#define BUFF_COMPL 2048 /* Taille de la ligne de commande (COMPL == completion) */

/* STRUCT */
/* structure principale */
typedef struct	s_info
{
  char		**env;
  char		*prompt;
  char		**path;
  int		status; /* valeur de retour du wait */
}		t_info;

/* xmalloc */
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

/* LOOP */
int		loop(t_info *info);

/* PARSEUR DU BUFFER*/
int		parse_str(t_info *info, char *str);

/* PROMPT */
void		prompt(t_info *info);
int		launch_fct(t_info *info, int i);
void		full_hostname(t_info *info);
void		hostname_to_dot(t_info *info);
void		pourcent(t_info *info);
void		tild(t_info *info);
void		user_name(t_info *info);

/* GERE_REDIRECT */
int		gere_redirect(t_info *info, char *str);
int		gere_dotcoma();
int		gere_left();
int		gere_pipe();
int		gere_right();
int		gere_bracket();
int		gere_or();
int		gere_and();
int		gere_double_left();
int		gere_double_right();

/* BUILTINS */
int		builtins(t_info *info, char *str);

/* COMMAND */
int		command();

/* EXEC */
int		exec(t_info *info, char *str);
int		my_access(t_info *info, char **tab);

/* LIB */
int		my_getnbr(char *str);
int		my_getnbr_base(char *str, char *base);
void		*my_memset(char *b, char c, int size);
void		my_put_nbr(int n);
int		my_putchar(char c);
int		my_putstr(char *str);
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
char		*fetch_env(char **env, char *str);
char		*get_next_line(const int fd);
int		my_putnbr_base(int n, char *base);
int		my_getnbr_base(char *str, char* base);

/* ERR */
void		*xmalloc(int size);
void		*mem_add(int rw, void *to_mem);
void		my_put_in_list(t_mal **begin, void *add);
void		*x_malloc(int size);
int		xopen(char *file);
int		xread(int fd, char *buf, int size);
int		xwrite(int fd, char *str, int size);
void		xfree(void *ptr);

#endif /* !__42_H__ */
