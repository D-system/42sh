/*
** gere_pipe.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:48:08 2008 laurent lefebvre
** Last update Mon Apr 28 12:32:25 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Gestion des pipes en recursif
*/

int	gere_pipe_put_zero(char *str)
{
  int	i;
  int	bracket;

  i = 0;
  bracket = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	bracket++;
      if (str[i] == '|' && bracket == 0)
	{
	  str[i] = '\0';
	  return (i);
	}
      if (str[i] == ')')
	bracket--;
      i++;
    }
  return (-1);
}

int	gere_pipe_next(t_info *info, char *str, int flag)
{
  int	pid;
  int	fildes[2];
  int	i;

  if ((i = gere_pipe_put_zero(str)) == -1)
    return (EXIT_FAILURE);
  if (xpipe(fildes) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((pid = xfork()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (pid == 0)
    {
      xclose(fildes[1]);
      if (xdup2(fildes[0], 0) == EXIT_FAILURE)
	{
	  xclose(fildes[0]);
	  return (EXIT_FAILURE);
	}
      return (gere_redirect(info, str + i + 1, CHILD));
    }
  else
    {
      xclose(fildes[0]);
      if (xdup2(fildes[1], 1) == EXIT_FAILURE)
	{
	  xclose(fildes[1]);
	  return (EXIT_FAILURE);
	}
      return (gere_redirect(info, str, flag));
    }
  return (EXIT_FAILURE);
}

int	gere_pipe(t_info *info, char *str, int flag)
{
  int	pid;
  int	status;

  if ((pid = xfork()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (pid == 0)
    gere_pipe_next(info, str, CHILD);
  else if (xwait(&status) == EXIT_FAILURE)
    info->status = EXIT_FAILURE;
  return (EXIT_SUCCESS);
}
