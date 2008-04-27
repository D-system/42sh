/*
** exec.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:49:16 2008 laurent lefebvre
** Last update Fri Apr 25 16:08:29 2008 thomas brennetot
*/

#include <stdlib.h>
#include <unistd.h>
#include "42.h"

/*
** Met les arguments dans un tableau, fork, execute
*/

int	exec(t_info *info, char *str)
{
  char	**tab;
  int	value_fork;
  int	status;

  if ((tab = my_str_to_wordtab(str)) == NULL)
    return (EXIT_FAILURE);
  if (tab[0] == NULL)
    return (EXIT_SUCCESS);
  if (my_access(info, tab) == EXIT_FAILURE)
    {
      free_tab(tab);
      return (EXIT_FAILURE);
    }
  value_fork = fork();
  if (value_fork == 0)
    {
      execve(tab[0], tab, info->env);
      exit(EXIT_FAILURE);
    }
  else
    xwait(&status);
  free_tab(tab);
  return (EXIT_FAILURE);
}
