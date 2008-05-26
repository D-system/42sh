/*
** gere_dotcoma.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:42:30 2008 laurent lefebvre
** Last update Thu May 15 11:47:47 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** gestion en recursif des ";" ne s'occupe des ";" uniquement si il n'y a pas de parentheses
*/

int	gere_dotcoma(t_info *info, char *str, int flag)
{
  int	i;
  int	value;

  if ((i = put_zero(str, ";")) == -1)
    return (EXIT_FAILURE);
  value = gere(info, str, flag);
  value += gere(info, str + i + 1, flag);
  if (value == 0)
    return (status(info, EXIT_SUCCESS));
  return (status(info, EXIT_FAILURE));  
}
