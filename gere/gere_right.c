/*
** gere_right.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Tue Apr 29 12:53:12 2008 thomas brennetot
** Last update Fri May 30 17:50:40 2008 laurent lefebvre
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>
#include "42.h"


int		gere_right_next(t_info *info, char *str, int flag)
{
  char		*file;
  char		buff[BUFF_COMPL];
  int		fd;
  int		value;

  if ((file = cdnarn(str, buff, ">")) == NULL)
    return (status(info, EXIT_FAILURE));
  if ((fd = xopen(file, O_CREAT | O_WRONLY | O_TRUNC)) == -1)
    {
      xfree(file);
      return (status(info, EXIT_FAILURE));
    }
  xfree(file);
  if (xdup2(fd, 1) == EXIT_FAILURE)
    {
      xclose(fd);
      return (status(info, EXIT_FAILURE));
    }
  value = gere(info, buff, flag);
  xclose(fd);
  return (value);
}

int		gere_right(t_info *info, char *str, int flag)
{
  int		pid;
  int		value;

  if (flag == CHILD)
    {
      value = gere_right_next(info, str, flag);
      exit(value);
    }
  else
    {
      if ((pid = xfork()) == -1)
	return (status(info, EXIT_FAILURE));
      if (pid == 0)
	{
	  value = gere_right_next(info, str, flag);
	  exit(value);
	}
      else if (xwaitpid(pid, &value, 0) == EXIT_FAILURE)
	return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}
