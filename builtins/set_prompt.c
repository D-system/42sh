/*
** set_prompt.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Sat May  3 16:35:33 2008 aymeric derazey
** Last update Thu May 29 23:27:42 2008 aymeric derazey
*/

#include "42.h"

int	set_prompt(t_info *info)
{
  int	i;
  char	*fetched;

  i = 0;
  if ((fetched = fetch_env(info->set, "prompt", "\t")) != NULL)
    {
      while (fetched[i++] != '\t');
      xfree(info->prompt);
      info->prompt = my_strdup(fetched + i);
    }
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
