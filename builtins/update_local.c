/*
** update_local.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Wed May 28 21:49:05 2008 aymeric derazey
** Last update Thu May 29 18:21:55 2008 aymeric derazey
*/

#include "42.h"

int	update_local(t_info *info, char *str, int fetched)
{
  if ((up_check_syntax(info, str, fetched)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	update_with_equal(t_info *info, char *str, int fetched)
{
  int	len;

  if (str == NULL)
    return (EXIT_FAILURE);
  len = 0;
  while ((str[len] != '=') && (str[len] != '\0'))
    len++;
  str[len] = '\0';
  info->set[fetched] = my_strcat_trois(str, "\t", str+len+1);
  return (EXIT_SUCCESS);
}

int	update_without_equal(t_info *info, char *str, int fetched)
{
  if (str == NULL)
    return (EXIT_FAILURE);
  info->set[fetched] = my_strdup(str);
  return (EXIT_SUCCESS);
}
