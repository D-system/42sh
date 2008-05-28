/*
** get_group.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/local
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Tue May 27 20:53:14 2008 aymeric derazey
** Last update Tue May 27 21:45:30 2008 aymeric derazey
*/

#include "42.h"
#include <grp.h>

int	get_group(t_info *info)
{
  char		*set_group;
  struct group	*grp;
  int		i;

  set_group = "group";
  if ((grp = getgrgid(getegid())) == NULL)
    return (EXIT_FAILURE);
  set_group = my_strcat_trois(set_group, "\t", grp->gr_name);
  i = 0;
  while (info->set[i] != NULL)
    i++;
  info->set[i++] = my_strdup(set_group);
  info->set[i] = NULL;
  return (EXIT_SUCCESS);
}
