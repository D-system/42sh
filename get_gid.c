/*
** get_grp.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Mon May 26 18:30:21 2008 aymeric derazey
** Last update Tue May 27 20:29:48 2008 aymeric derazey
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "42.h"

void	get_gid(t_info *info)
{
  char	*set_grp;
  char	*gid_str;
  int	i;

  gid_str = int_to_str(getegid());
  set_grp = "gid";
  gid_str = my_strcat_trois(set_grp, "\t", gid_str);
  i = 0;
  while (info->set[i] != NULL)
    i++;
  info->set[i++] = my_strdup(gid_str);
  info->set[i] = NULL;
}
