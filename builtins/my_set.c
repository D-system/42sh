/*
** my_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  2 22:12:11 2008 aymeric derazey
** Last update Sat May  3 17:39:33 2008 aymeric derazey
*/

#include "../42.h"

struct	s_set	gl_set[] =
  {
    {"prompt", set_prompt, 6},
    {"history", set_history, 7},
    {0,0,0},
  };

int	my_set(t_info *info, char **tab)
{
  int	i;

  if (tab[1] == NULL)
    aff_set(info);
  i = 0;
  while (gl_set[i].cmd != 0)
    {
      if ((my_strncmp(gl_set[i].cmd, tab[1], gl_set[i].len) == 0))
	if (gl_set[i].func(info, tab) == EXIT_FAILURE)
	  return (status(info, EXIT_FAILURE));
      i++;
    }
  return (EXIT_SUCCESS);
}

int	aff_set(t_info *info)
{
  int	i;
  
  i = 0;
  while (info->set[i] != NULL)
    {
      my_printf("%s\n", info->set[i]);
      i++;
    }
  return (EXIT_SUCCESS);
}
