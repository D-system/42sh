/*
** get_grp.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Mon May 26 18:30:21 2008 aymeric derazey
** Last update Fri May 30 00:07:16 2008 aymeric derazey
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "42.h"

void	get_gid(t_info *info)
{
  char	*gid_str1;
  char	*gid_str2;
  int	i;

  gid_str1 = int_to_str(getegid());
  gid_str2 = my_strcat_trois("gid", "\t", gid_str1);
  i = 0;
  while (info->set[i] != NULL)
    i++;
  info->set[i++] = my_strdup(gid_str2);
  info->set[i] = NULL;
  xfree(gid_str1);
  xfree(gid_str2);
}
