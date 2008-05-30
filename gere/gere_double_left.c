/*
** gere_double_left.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:49:36 2008 thomas brennetot
** Last update Fri May 30 17:51:07 2008 laurent lefebvre
*/

#include <stdlib.h>
#include <fcntl.h>
#include "42.h"

int		gere_double_left_next(t_info *info, char *str, int flag)
{
  char	*stop;
  char	buff[BUFF_COMPL];
  int	value;

  if ((stop = cdnarn(str, buff, "<<")) == NULL)
    return (status(info, EXIT_FAILURE));
  value = gere(info, buff, flag);
  xfree(stop);
  return (value);
}

int	gere_double_left(t_info *info, char *str, int flag)
{
  int		pid;
  int		value;

  if (flag == CHILD)
    gere_double_left_next(info, str, flag);
  else
    {
      if ((pid = xfork()) == -1)
	return (status(info, EXIT_FAILURE));
      if (pid == 0)
	{
	  exit(gere_double_left_next(info, str, CHILD));
	}
      else if (xwaitpid(pid, &value, 0) == EXIT_FAILURE)
	return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}
