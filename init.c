/*
** init.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
** Last update Mon May 26 18:22:20 2008 laurent lefebvre
*/

#include <stdlib.h>
#include <signal.h>
#include "42.h"

/*
** memset la structure, recupere l'env et lit le fichier de conf.
*/

int	init(char **environ, t_info *info)
{
  my_memset(info, 0, sizeof(*info));
  info->last_status = EXIT_SUCCESS;
  info->set = 0;
  get_env(environ, info);
  get_set(info);
  info->path = path_to_tab(fetch_env(info->env, "PATH", "="));
  info->pwd = my_pwd();
/*   if (get_cfg(info) == EXIT_FAILURE) */
/*       return (EXIT_FAILURE); */
  load_event(info);
  return (EXIT_SUCCESS);
}
