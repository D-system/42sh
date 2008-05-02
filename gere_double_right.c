/*
** gere_double_right.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:49:36 2008 thomas brennetot
** Last update Fri May  2 14:28:02 2008 thomas brennetot
*/

#include <stdlib.h>
#include <fcntl.h>
#include "42.h"

int		gere_double_right_next(t_info *info, char *str, int flag)
{
  char		*file;
  char		buff[BUFF_COMPL];
  int		fd;

  if ((file = cut_delim_nextword_and_return_nextword(str, buff, ">>")) == NULL)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  if ((fd = xopen(file, O_CREAT | O_WRONLY | O_APPEND)) == -1)
    {
      xfree(file);
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  xfree(file);
  if (xdup2(fd, 1) == EXIT_FAILURE)
    {
      xclose(fd);
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  gere(info, buff, flag);
  xclose(fd);
  return (EXIT_SUCCESS);
}

int		gere_double_right(t_info *info, char *str, int flag)
{
  int		pid;
  int		status;

  if (flag == CHILD)
    gere_double_right_next(info, str, flag);
  else
    {
      if ((pid = xfork()) == -1)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
      if (pid == 0)
	gere_double_right_next(info, str, CHILD);
      else if (xwaitpid(pid, &status, 0) == EXIT_FAILURE)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
