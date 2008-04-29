/*
** gere_dotcoma.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:42:30 2008 laurent lefebvre
** Last update Tue Apr 29 12:07:19 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

/*
** gestion en recursif des ";" ne s'occupe des ";" uniquement si il n'y a pas de parentheses
*/

int	gere_dotcoma(t_info *info, char *str, int flag)
{
  int	i;

  if ((i = put_zero(str, ";")) == -1)
    return (EXIT_FAILURE);
  gere_redirect(info, str, flag);
  gere_redirect(info, str + i + 1, flag);
  return (EXIT_SUCCESS);
}
