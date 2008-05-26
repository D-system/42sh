/*
** get_grp.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Mon May 26 18:30:21 2008 aymeric derazey
** Last update Mon May 26 18:38:01 2008 aymeric derazey
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "42.h"

int	get_gid(t_info *info)
{
  char	*set_grp;
  uid_t	gid;
  int	i;
  char	*user_gid;

  gid = getegid();
  printf("this is the gid : %d\n", gid);
  set_grp = "gid";
  user_gid = my_strcat_trois(set_grp, "\t", "32012");
  i = 0;
  while (info->set[i] != NULL)
    i++;
  info->set[i] = my_strdup(user_gid);
  i++;
  info->set[i] = NULL;
  return (EXIT_SUCCESS);
}
