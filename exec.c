/*
** exec.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:49:16 2008 laurent lefebvre
** Last update Mon Apr 28 12:14:35 2008 thomas brennetot
*/

#include <stdlib.h>
#include <unistd.h>
#include "42.h"

/*
** Met les arguments dans un tableau, fork, execute
*/

void	exec_direct(t_info *info, char **tab)
{
  execve(tab[0], tab, info->env);
  exit(EXIT_FAILURE);
}

void	exec_fork(t_info *info, char **tab)
{
  int	status;
  int	pid;

  if ((pid = xfork()) == EXIT_FAILURE)
    {
      info->status = EXIT_FAILURE;
      return ;
    }
  if (pid == 0)
    {
      execve(tab[0], tab, info->env);
      exit(EXIT_FAILURE);
    }
  else if (xwait(&status) == EXIT_FAILURE)
    info->status = EXIT_FAILURE;
}

void	exec(t_info *info, char *str, int flag)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(str)) == NULL)
    return ;
  if (tab[0] == NULL)
    return ;
  if (my_access(info, tab) == EXIT_FAILURE)
    {
      free_tab(tab);
      info->status = EXIT_FAILURE;
      return ;
    }
  if (flag == CHILD)
    exec_direct(info, tab);
  else
    exec_fork(info, tab);
  free_tab(tab);
  return ;
}
