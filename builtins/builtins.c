/*
** builtins.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat May 31 00:33:43 2008 aymeric derazey
** Last update Sun Jun  1 03:05:14 2008 laurent lefebvre
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
  {"unset", my_unset},
  {"alias", set_alias},
  {0, 0},
};

int	builtins(t_info *info, char *str) /* NORME */
{
  int	ibui;
  char	**tab;
  int	value;

  if ((tab = my_str_to_wordtab(str)) == NULL) /* was my... */
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
