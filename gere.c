/*
** gere_redirect.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:33:56 2008 laurent lefebvre
** Last update Tue May 27 21:42:41 2008 aymeric derazey
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
/*   debug("***** La ligne apres decoupage ****** %s\n", str); */
  if ((value = builtins(info, str)) == NO_BUILTINS)
    if (exec(info, str, flag) == EXIT_FAILURE)
      {
/* 	debug("\nErreur des exec\n\n\n"); */
	return (EXIT_FAILURE);
      }
  return (value);
}
