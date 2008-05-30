/*
** gere_left.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:43:44 2008 laurent lefebvre
** Last update Fri May 30 17:50:21 2008 laurent lefebvre
*/

#include <stdlib.h>
#include <fcntl.h>
#include "42.h"

/*
** gestion en recursif des redirections gauche
*/

int		gere_left_next(t_info *info, char *str, int flag)
{
  char		*file;
  char		buff[BUFF_COMPL];
  int		fd;
  int		value;

  if ((file = cdnarn(str, buff, "<")) == NULL)
    return (status(info, EXIT_FAILURE));
  if ((fd = xopen(file, O_RDONLY)) == -1)
    {
      xfree(file);
      return (status(info, EXIT_FAILURE));
    }
  xfree(file);
  if (xdup2(fd, 0) == EXIT_FAILURE)
    {
      xclose(fd);
      return (status(info, EXIT_FAILURE));
    }
  value = gere(info, buff, flag);
  xclose(fd);
  return (value);
}


int		gere_left(t_info *info, char *str, int flag)
{
  int		pid;
  int		value;

  if (flag == CHILD)
    {
      value = gere_left_next(info, str, flag);
      exit(value);
    }
  else
    {
      if ((pid = xfork()) == -1)
	return (status(info, EXIT_FAILURE));
      if (pid == 0)
	{
	  value = gere_left_next(info, str, flag);
	  exit(value);
	}
      else if (xwaitpid(pid, &value, 0) == EXIT_FAILURE)
	return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}
