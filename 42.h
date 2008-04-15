/*
** 42.h for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/official
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Mon Mar 31 17:18:10 2008 aymeric derazey
** Last update Tue Apr 15 18:15:55 2008 thomas brennetot
*/

#ifndef __42_H__
# define __42_H__

/* DEFINES */
#define BUFF_SIZE 2048

/* STRUCT */
/* structure principale */
typedef struct	s_info
{
  char		**env;
  char		*prompt;
}		t_info;

/* ? */
typedef struct		s_mal
{
  void			*addr;
  struct	s_mal	*next;
}			t_mal;

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

/* LOOP */
int		loop();

/* PROMPT */
int		prompt(t_info *info);
int		launch_fct(t_info *info, int i);
void		full_hostname(t_info *info);
void		hostname_to_dot(t_info *info);
void		pourcent(t_info *info);
void		tild(t_info *info);
void		user_name(t_info *info);

/* GERE_REDIRECT */
void		gere_redirect();
void		gere_dotcoma();
void		gere_left();
void		gere_pipe();
void		gere_right();

/* COMMAND */
void		command();

/* EXEC */
void		exec();

/* LIB */
int		my_getnbr(char *str);
int		my_getnbr_base(char *str, char *base);
void		*my_memset(char *b, char c, int size);
void		my_put_nbr(int n);
int		my_putchar(char c);
int		my_putstr(char *str);
char		**my_str_to_wordtab(char *str);
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
