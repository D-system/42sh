/*
** init.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu May 29 18:53:22 2008 aymeric derazey
** Last update Thu May 29 22:46:59 2008 aymeric derazey
*/

#include <stdlib.h>
#include <signal.h>
#include "42.h"

/*
** memset la structure, recupere l'env et lit le fichier de conf.
*/

void	init(char **environ, t_info *info)
{
  my_memset(info, 0, sizeof(*info));
  info->last_status = EXIT_SUCCESS;
  info->alias = xmalloc(sizeof(*info->alias));
  my_memset(info->alias, 0, sizeof(*(info->alias)));
  get_env(environ, info);
  get_set(info);
  get_local(info);
  info->pwd = my_pwd();
  info->path = path_to_tab(fetch_env(info->env, "PATH", "="));
  get_cfg(info);
  load_event(info);
}
