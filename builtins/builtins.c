/*
** builtins.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 23 16:27:35 2008 thomas brennetot
** Last update Sat May  3 00:32:37 2008 aymeric derazey
*/

#include <stdlib.h>
#include "../42.h"

struct s_bui	gl_bui[] =
{
  {"cd", my_cd},
  {"env", my_env},
  {"exit", my_exit},
  {"setenv", my_setenv},
  {"unsetenv", my_unsetenv},
  {"history", aff_event},
  {"echo", my_echo},
/*   {"set", my_set}, */
  {0, 0},
};

int	builtins(t_info *info, char *str)
{
  int	ibui;
  char	**tab;
  int	value;

  if ((tab = my_str_to_wordtab(str)) == NULL)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  ibui = 0;
  while (gl_bui[ibui].str != 0)
    {
      if (my_strcmp(gl_bui[ibui].str, tab[0]) == 0)
	{
	  if ((value = gl_bui[ibui].func(info, tab)) == EXIT_FAILURE)
	    info->last_status = EXIT_FAILURE;
	  free_tab(tab);
	  return (value);
	}
      ibui++;
    }
  free_tab(tab);
  return (NO_BUILTINS);
}
