/*
** gere_double_right.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:49:36 2008 thomas brennetot
** Last update Tue Apr 29 18:31:42 2008 thomas brennetot
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>
#include "42.h"

int		gere_double_right_next(t_info *info, char *str, int flag)
{
  char		*file;
  char		buff[BUFF_COMPL];
  int		fd;

  debug("%E", "gere_double_right_next\n");
  if ((file = cut_delim_nextword_and_return_nextword(str, buff, ">>")) == NULL)
    return (EXIT_FAILURE);
  debug("%E%E%E", "le file a ouvrir dans >> ", file, "\n");
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
  gere_redirect(info, buff, flag);
  xclose(fd);
  return (EXIT_SUCCESS);
}

int		gere_double_right(t_info *info, char *str, int flag)
{
  int		pid;
  int		status;
  struct rusage	rusage;

  debug("%E", "gere_double_right_next\n");
  if (flag == CHILD)
    gere_right_next(info, str, flag);
  else
    {
      if ((pid = xfork()) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (pid == 0)
	{
	  debug("%E", "NNNOONNNNN\n");
	  gere_double_right_next(info, str, CHILD);
	}
      else if (xwait4(pid, &status, 0, &rusage) == EXIT_FAILURE)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
