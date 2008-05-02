/*
** init.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
** Last update Fri May  2 20:05:51 2008 thomas brennetot
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
  info->last_status = EXIT_SUCCESS;
  get_env(environ, info);
  info->path = path_to_tab(fetch_env(info->env, "PATH"));
  info->history = NULL;
  info->nbr_cmd = 0;
/*   if (get_cfg(info) == EXIT_FAILURE) */
/*       return (EXIT_FAILURE); */
  load_event(info);
  return (EXIT_SUCCESS);
}
