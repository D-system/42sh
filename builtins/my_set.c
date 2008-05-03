/*
** my_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  2 22:12:11 2008 aymeric derazey
** Last update Fri May  2 23:32:47 2008 aymeric derazey
*/

#include "../42.h"

struct	s_set	gl_set[] =
  {
    {"prompt", my_prompt, 6},
    {"history", my_history, 7},
    {0,0,0},
  };

int	my_set(t_info *info, char **tab)
{
  int	i;

  if (tab[1] == NULL)
    aff_set(info);
  while (gl_set[i].str != 0)
    {
      if (my_strncmp(gl_set[i].str, tab[1], gl_set[i].len == 0)
	  if (gl_set[i].func(info, tab)) == EXIT_FAILURE)
	return (last_status(EXIT_FAILURE));
    }
  i++;
  return (EXIT_SUCCESS);
}

int	aff_set(t_info *info)
{
  
}




int	last_status(int status)
{
  info->status = status;
  return (status);
}
