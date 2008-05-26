/*
** gere_and.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:49:36 2008 thomas brennetot
** Last update Thu May 15 11:44:48 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

int	gere_and(t_info *info, char *str, int flag)
{
  int	i;

  if ((i = put_zero(str, "&&")) == -1)
    return (status(info, EXIT_FAILURE));
  if (gere(info, str, flag) == EXIT_FAILURE)
    return (status(info, EXIT_FAILURE));
  if (gere(info, str + i + 2, flag) == EXIT_FAILURE)
    return (status(info, EXIT_FAILURE));
  return (EXIT_SUCCESS);
}
