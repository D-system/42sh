/*
** gere_left.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:43:44 2008 laurent lefebvre
** Last update Wed Apr 30 10:32:54 2008 thomas brennetot
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>
#include "42.h"

/*
** gestion en recursif des redirections gauche
*/

int		gere_left_next(t_info *info, char *str, int flag)
{
  char		*file;
  char		buff[BUFF_COMPL];
  int		fd;

  if ((file = cut_delim_nextword_and_return_nextword(str, buff, "<")) == NULL)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  if ((fd = xopen(file, O_RDONLY)) == -1)
    {
      xfree(file);
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  xfree(file);
  if (xdup2(fd, 0) == EXIT_FAILURE)
    {
      xclose(fd);
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  gere(info, buff, flag);
  xclose(fd);
  return (EXIT_SUCCESS);
}


int		gere_left(t_info *info, char *str, int flag)
{
  int		pid;
  int		status;
  struct rusage	rusage;

  if (flag == CHILD)
    gere_left_next(info, str, flag);
  else
    {
      if ((pid = xfork()) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (pid == 0)
	gere_left_next(info, str, CHILD);
      else if (xwait4(pid, &status, 0, &rusage) == EXIT_FAILURE)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
