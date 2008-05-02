/*
** gere_pipe.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:48:08 2008 laurent lefebvre
** Last update Fri May  2 14:22:42 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Gestion des pipes en recursif
*/

int		gere_pipe_next(t_info *info, char *str, int flag, int i, int *fildes)
{
  int		pid;

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
      return (gere(info, str + i + 1, CHILD));
    }
  else
    {
      xclose(fildes[0]);
      if (xdup2(fildes[1], 1) == EXIT_FAILURE)
	{
	  xclose(fildes[1]);
	  return (EXIT_FAILURE);
	}
      return (gere(info, str, flag));
    }
  return (EXIT_FAILURE);
}

int		gere_pipe(t_info *info, char *str, int flag)
{
  int		pid;
  int		status;
  int		fildes[2];
  int		i;

  if ((pid = xfork()) == EXIT_FAILURE)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  if (pid == 0)
    {
      if ((i = put_zero(str, "|")) == -1)
	return (EXIT_FAILURE);
      if (xpipe(fildes) == EXIT_FAILURE)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
      gere_pipe_next(info, str, CHILD, i, fildes);
    }
  else if (xwaitpid(pid, &status, 0) == EXIT_FAILURE)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  flag++;
  return (EXIT_SUCCESS);
}
