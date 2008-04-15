/*
** hostname_to_dot.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/prompt
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Tue Apr 15 15:48:02 2008 aymeric derazey
** Last update Tue Apr 15 17:49:22 2008 thomas brennetot
*/

#include <stdlib.h>
#include <unistd.h>
#include "../42.h"

void	hostname_to_dot(t_info *info)
{
  char	*host;
  int	i;

  host = fetch_env(info->env, "HOST");
  if (host != NULL)
    {
      i = 0;
      while (host[i] != '.' && host[i] != '\0')
	  i++;
      write(1, host + 5, i - 5);
    }
}

