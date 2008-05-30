/*
0** builtins.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Wed Apr 23 16:27:35 2008 thomas brennetot
** Last update Fri May 30 18:31:46 2008 laurent lefebvre
*/

#include <stdlib.h>
#include "42.h"

struct s_bui	gl_bui[] =
{
  {"cd", my_cd},
  {"env", my_env},
  {"exit", my_exit},
  {"setenv", my_setenv},
  {"unsetenv", my_unsetenv},
  {"history", aff_event},
  {"echo", my_echo},
  {"set", my_set},
  {"alias", set_alias},
  {0, 0},
};

int	builtins(t_info *info, char *str) /* NORME */
{
  int	ibui;
  char	**tab;
  int	value;

  if ((tab = str_to_wordtab(str, " \t")) == NULL) /* was my... */
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  if (my_alias(info, tab, str) != NO_BUILTINS)
    {
      free_tab(tab);
      return (EXIT_FAILURE);
    }
  ibui = 0;
  while (gl_bui[ibui].str != 0)
    {
      if (!my_strcmp(gl_bui[ibui].str, tab[0]) &&
	  my_strlen(tab[0]) == my_strlen(gl_bui[ibui].str))
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
