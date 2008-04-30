/*
** gere_double_left.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:49:36 2008 thomas brennetot
** Last update Wed Apr 30 09:59:05 2008 thomas brennetot
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>
#include "42.h"

int	gere_double_left(t_info *info, char *str, int flag)
{
  int		pid;
  int		status;
  struct rusage	rusage;

  if (flag == CHILD)
    gere_double_left_next(info, str, flag);
  else
    {
      if ((pid = xfork()) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (pid == 0)
	gere_double_left_next(info, str, CHILD);
      else if (xwait4(pid, &status, 0, &rusage) == EXIT_FAILURE)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

int		gere_double_left_next(t_info *info, char *str, int flag)
{
  char	*stop;
  char	buff[BUFF_COMPL];

  if ((stop = cut_delim_nextword_and_return_nextword(str, buff, "<<")) == NULL)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  
  xfree(stop);
  return (EXIT_SUCCESS);
}

