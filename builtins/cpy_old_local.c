/*
** cpy_old_local.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Wed May 28 19:55:27 2008 aymeric derazey
** Last update Thu May 29 18:21:23 2008 aymeric derazey
*/

#include "42.h"

/*
** copie l'ancien tableau local et renvoie une copie
** avec l'espace necessaire.
*/

char	**cpy_old_local(t_info *info)
{
  int	i;
  char **new_local;

  i = 0;
  while (info->set[i] != NULL)
    i++;
  if ((new_local = xmalloc(sizeof(*new_local) * (i + 2))) == NULL)
    return (NULL);
  i = 0;
  while (info->set[i] != NULL)
    {
      new_local[i] = info->set[i];
      i++;
    }
  new_local[i] = NULL;
  return (new_local);
}
