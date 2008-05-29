/*
** get_user.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May 15 16:29:36 2008 aymeric derazey
** Last update Fri May 30 00:18:22 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

int	get_user(t_info *info)
{
  char	*user1;
  char	*user2;

  if ((user1 = getlogin()) == NULL)
    return (EXIT_FAILURE);
  user2 = my_strcat_trois("user", "\t", user1);
  info->set[0] = my_strdup(user2);
  info->set[1] = NULL;
  xfree(user1);
  xfree(user2);
  return (EXIT_SUCCESS);
}
