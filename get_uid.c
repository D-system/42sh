/*
** get_uid.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May 15 16:46:11 2008 aymeric derazey
** Last update Mon May 26 18:16:11 2008 aymeric derazey
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "42.h"

int	get_uid(t_info *info)
{
  char	*set_uid;
  uid_t	uid;
  int	i;
  char	*user_uid;

  uid = getuid();
  set_uid = "uid";
  user_uid = my_strcat_trois(set_uid, "\t", "72275");
  i = 0;
    while (info->set[i] != NULL)
      i++;
  info->set[i] = my_strdup(user_uid);
  i++;
  info->set[i] = NULL;
  return (EXIT_SUCCESS);
}
