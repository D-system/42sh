/*
** my_env.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/builtins
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 30 12:54:06 2008 thomas brennetot
** Last update Wed Apr 30 12:57:59 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

int	my_env(t_info *info, char **tab)
{
  int	i;

  i = 0;
  if (info->env != NULL)
    while (info->env[i] != NULL)
      my_printf("%s\n", info->env[i++]);
  tab++;
  return (EXIT_SUCCESS);
}
