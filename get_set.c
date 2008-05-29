/*
** get_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Fri May  2 23:34:02 2008 aymeric derazey
** Last update Thu May 29 22:55:49 2008 aymeric derazey
*/

#include <sys/types.h>
#include <stdlib.h>
#include <grp.h>
#include <unistd.h>
#include "42.h"

int	get_set(t_info *info)
{
  int	size;

  size = get_size();
  if ((info->set = xmalloc(sizeof(*(info->set)) * (size + 1))) == NULL)
    return (EXIT_FAILURE);
  if ((get_user(info)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((get_group(info)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  get_uid(info);
  get_gid(info);
  return (EXIT_SUCCESS);
}
