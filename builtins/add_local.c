/*
** add_local.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu May 29 18:59:25 2008 aymeric derazey
** Last update Thu May 29 18:59:28 2008 aymeric derazey
*/

#include "42.h"

/*
** ajoute une ou plusieurs variables locales qui n'existent pas encore
*/

int	add_local(t_info *info, char *str)
{
  char	**new_local;

  if ((new_local = cpy_old_local(info)) == NULL)
    return (EXIT_FAILURE);
  if ((check_syntax(info, str, new_local)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	add_with_equal(t_info *info, char *str, char **new_local)
{
  int	i;
  int	len;

  if (str == NULL)
    return (EXIT_FAILURE);
  len = 0;
  while ((str[len] != '=') && (str[len] != '\0'))
    len++;
  str[len] = '\0';
  i = 0;
  while (info->set[i] != NULL)
      i++;
  new_local[i++] = my_strcat_trois(str, "\t", str+len+1);
  new_local[i] = NULL;
  info->set = new_local;
  return (EXIT_SUCCESS);
}

int	add_without_equal(t_info *info, char *str, char **new_local)
{
  int	i;

  if (str == NULL)
    return (EXIT_FAILURE);
  i = 0;
  while (info->set[i] != NULL)
    i++;
  new_local[i++] = my_strdup(str);
  new_local[i] = NULL;
  info->set = new_local;
  return (EXIT_SUCCESS);
}
