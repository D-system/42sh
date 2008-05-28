/*
** user_name.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Tue Apr 15 17:56:25 2008 thomas brennetot
** Last update Tue May 27 19:32:11 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

void	user_name(t_info *info)
{
  char	*user;

  user = fetch_env(info->env, "USER", "=");
  if (user != NULL)
    my_putstr(user + 5);
}
