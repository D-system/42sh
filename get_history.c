/*
** get_history.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/local
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Tue May 27 20:21:49 2008 aymeric derazey
** Last update Tue May 27 20:35:59 2008 aymeric derazey
*/

#include "42.h"

void	get_history(t_info *info)
{
  char	*set_history;
  int	i;

  set_history = "history";
  set_history = my_strcat_trois(set_history, "\t", "100");
  i = 0;
  while (info->set[i] != NULL)
    i++;
  info->set[i++] = my_strdup(set_history);
  info->set[i] = NULL;
}
