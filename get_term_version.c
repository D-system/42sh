/*
** get_term_version.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu May 29 22:32:09 2008 aymeric derazey
** Last update Thu May 29 22:54:16 2008 aymeric derazey
*/

#include "42.h"

void	get_term_version(t_info *info)
{
  int	i;

  i = 0;
  while (info->set[i] != NULL)
    i++;
  info->set[i++] = my_strdup("42sh\t0.42");
  info->set[i] = NULL;
}
