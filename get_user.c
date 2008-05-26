/*
** get_user.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May 15 16:29:36 2008 aymeric derazey
** Last update Thu May 15 17:28:46 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

int	get_user(t_info *info)
{
  char	*set_user;
  char	*user;

  set_user = "user";
  if ((user = getlogin()) == NULL)
    return (EXIT_FAILURE);
  user = my_strcat_trois(set_user, "\t", user);
  info->set[0] = my_strdup(user);
  info->set[1] = NULL;
  return (EXIT_SUCCESS);
}
