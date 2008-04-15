/*
** init.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
** Last update Sat Apr 12 15:47:54 2008 thomas brennetot
*/

#include "42.h"
#include <stdlib.h>

/*
** Set TOUTES les variables a NULL, recupere l'env et lit le fichier de conf
*/

int	init(char **environ, t_info *info)
{
  info->env = NULL;
  info->prompt = NULL;
  if (get_env(environ, info) == EXIT_FAILURE)
      return (EXIT_FAILURE);
/*   if (get_cfg(info) == EXIT_FAILURE) */
/*       return (EXIT_FAILURE); */
  return (EXIT_SUCCESS);
}
