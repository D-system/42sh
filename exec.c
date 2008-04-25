/*
** exec.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:49:16 2008 laurent lefebvre
** Last update Thu Apr 24 18:37:17 2008 aymeric derazey
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

  my_printf("16\n");
  if ((tab = my_str_to_wordtab(str)) == NULL)
    return (EXIT_FAILURE);
  my_printf("13\n");
  if (my_access(info, tab) == EXIT_FAILURE)
    {
      free_tab(tab);
      exit(EXIT_FAILURE);
    }
  my_printf("14\n");
  execve(tab[0], tab, info->env);
  my_printf("15\n");
  free_tab(tab);
  exit(EXIT_FAILURE);
  return (EXIT_FAILURE);
}
