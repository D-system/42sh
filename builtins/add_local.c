/*
** add_local.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May  8 16:44:30 2008 aymeric derazey
** Last update Wed May 28 17:34:22 2008 aymeric derazey
*/

#include "42.h"

/*
** oLoL
*/

int	add_local(t_info *info, char **tab)
{
  char	**new_local;

  if ((new_local = cpy_old_local(info, tab)) != NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

/*
** copie l'ancien tableau local et renvoie une copie
** avec l'espace necessaire.
*/

char	**cpy_old_local(t_info *info, char **tab)
{
  int	i;
  int	add;
  char **new_local;

  add = 1;
  while (tab[add] != NULL)
    add++;
  if ((new_local = xmalloc(sizeof(*new_local) * (i + add + 1))) == NULL)
    return (NULL);
  i = 0;
  while (info->set[i] != NULL)
    {
      new_local[i] = info->set[i];
      i++;
    }
  i = 0;
  add = 1;
  while (tab[add] != NULL)
    {
      new_local[i]= tab[add];
      i++;
      add++;
    }
  new_local[i] = NULL;
  return (new_local);
}
