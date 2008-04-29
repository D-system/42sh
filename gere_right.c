/*
** gere_right.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Tue Apr 29 12:53:12 2008 thomas brennetot
** Last update Tue Apr 29 16:40:43 2008 thomas brennetot
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/resource.h>
#include "42.h"
#define BUFF_RIGHT BUFF_COMPL

void		*gere_right_tab(char *str, char *buff)
{
  int		i;
  char		**wordtab;
  char		*file;
  int		len;
  int		u;

  my_memset(buff, 0, BUFF_RIGHT);
  i = -1;
  while (str[++i] != '>')
    buff[i] = str[i];
  buff[i++] = ' ';
  if ((wordtab = my_str_to_wordtab(str + i)) == NULL)
    return (NULL);
  if ((file = my_strdup(wordtab[0])) == NULL)
    {
      free_tab(wordtab);
      return (NULL);
    }
  len = my_strlen(wordtab[0]);
  u = i;
  while (my_strncmp(&str[i++], wordtab[0], len) != 0);
  i += len;
  my_strcpy(&buff[u], &str[i]);
  free_tab(wordtab);
  return (file);
}

int		gere_right_next(t_info *info, char *str, int flag)
{
  char		*file;
  char		buff[BUFF_RIGHT];
  int		fd;

  if ((file = gere_right_tab(str, buff)) == NULL)
    return (EXIT_FAILURE);
  if ((fd = xopen(file, O_CREAT | O_WRONLY | O_TRUNC)) == EXIT_FAILURE)
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

int		gere_right(t_info *info, char *str, int flag)
{
  int		pid;
  int		status;
  struct rusage	rusage;

  if (flag == CHILD)
    gere_right_next(info, str, flag);
  else
    {
      if ((pid = xfork()) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (pid == 0)
	gere_right_next(info, str, CHILD);
      else if (xwait4(pid, &status, 0, &rusage) == EXIT_FAILURE)
	{
	  info->last_status = EXIT_FAILURE;
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_FAILURE);
}
