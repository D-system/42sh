/*
** get_env.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Fri Apr  4 16:34:52 2008 laurent lefebvre
** Last update Tue May 27 15:09:11 2008 laurent lefebvre
*/

#include "42.h"
#include <stdlib.h>

int	get_env(char **environ, t_info *info)
{
  int	i;

  i = 0;
  while (environ[i] != NULL)
    ++i;
  if ((info->env = xmalloc(sizeof(*(info->env)) * (i + 1))) == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (environ[i] != NULL)
    {
      if ((info->env[i] = my_strdup(environ[i])) == NULL)
	{
	  free_tab(info->env);
	  return (EXIT_FAILURE);
	}
      ++i;
    }
  info->env[i] = NULL;
  return (EXIT_SUCCESS);
}
