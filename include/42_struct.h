/*
** 42_struct.h for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/include
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** Started on  Tue May 27 19:48:51 2008 aymeric derazey
** Last update Fri May 30 03:43:33 2008 thomas brennetot
*/


#ifndef __42_STRUCT_H__
# define __42_STRUCT_H__


/* structure for alias gestion */
typedef	struct		s_alias
{
  char			*alias;
  char			*cmd;
  struct s_alias	*next;
}			t_alias;


/* Struct list chaine pour l'historique */

typedef struct		s_event
{
  int			nbr;
  char			*time;
  char			*info;
  struct s_event	*next;
  struct s_event	*prev;
}			t_event;

/* structure principale */

typedef struct	s_info
{
  char		**env;
  char		**set;
  char		**path;
/*   char		*prompt; */
  int		size_prompt;
  int		last_status; /* valeur de retour du wait */
  t_event	*history;
  t_event	*history_r;
  int		hist_max;
  int		nbr_cmd;
  int		hist_m;
  char		*pwd;
  char		*last_pwd;
  t_alias	*alias; /* liste chainee des alias */
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

enum {KEY_UP, HEY_DOWN, KEY_RIGHT, KEY_DOWN,
      KEY_LEFT, KEY_DEL, KEY_BACK, KEY_ENTER};

#endif /* __42_STRUCT_H__ */
