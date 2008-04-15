/*
** full_hostname.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/prompt
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Tue Apr 15 15:44:56 2008 thomas brennetot
** Last update Tue Apr 15 17:47:06 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

void	full_hostname(t_info *info)
{
  char	*name;

  name = fetch_env(info->env, "HOST");
  if (name != NULL)
    my_putstr(name + 5);
}
