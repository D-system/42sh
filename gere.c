/*
** gere_redirect.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:33:56 2008 laurent lefebvre
** Last update Wed Apr 30 11:43:52 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Fonction de recursivite. Appels:
** - gere_dotcoma si ";"
** - gere_left si "<"
** - gere_pipe si "|"
** - gere_right si ">"
** - command si instruction valide
*/

/*
** execute la ligne une fois decoupee.
*/

int	gere(t_info *info, char *str, int flag)
{
  int	value;

  if ((value = gere_delimitor(info, str, flag)) != NO_REDIRECTION)
    return (value);
  if ((value = gere_redirect(info, str, flag)) != NO_REDIRECTION)
    return (value);
  debug("%E%E%E", "***** La ligne apres decoupage ****** ", str, "\n");
  if ((value = builtins(info, str)) == NO_BUILTINS)
    if (exec(info, str, flag) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (value);
}
