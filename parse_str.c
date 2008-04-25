/*
** parse_str.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Thu Apr 24 13:45:22 2008 thomas brennetot
** Last update Thu Apr 24 13:47:05 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Parse la str avant de l'envoyer a gere_redirect
*/

int	parse_str(t_info *info, char *str)
{
  gere_redirect(info, str);
  return (EXIT_SUCCESS);
}
