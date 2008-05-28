/*
** get_uid.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May 15 16:46:11 2008 aymeric derazey
** Last update Tue May 27 20:30:13 2008 aymeric derazey
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "42.h"

void	get_uid(t_info *info)
{
  char	*set_uid;
  char	*str_uid;
  int	i;

  str_uid = int_to_str(getuid());
  set_uid = "uid";
  str_uid = my_strcat_trois(set_uid, "\t", str_uid);
  i = 0;
    while (info->set[i] != NULL)
      i++;
  info->set[i++] = my_strdup(str_uid);
  info->set[i] = NULL;
}
