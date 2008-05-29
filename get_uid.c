/*
** get_uid.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May 15 16:46:11 2008 aymeric derazey
** Last update Fri May 30 00:08:04 2008 aymeric derazey
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "42.h"

void	get_uid(t_info *info)
{
  char	*str_uid1;
  char	*str_uid2;
  int	i;

  str_uid1 = int_to_str(getuid());
  str_uid2 = my_strcat_trois("uid", "\t", str_uid1);
  i = 0;
    while (info->set[i] != NULL)
      i++;
  info->set[i++] = my_strdup(str_uid2);
  info->set[i] = NULL;
  xfree(str_uid1);
  xfree(str_uid2);
}
