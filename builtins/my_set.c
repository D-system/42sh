/*
** my_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Fri May  2 22:12:11 2008 aymeric derazey
** Last update Thu May 29 22:37:49 2008 thomas brennetot
*/

#include "42.h"

int	my_set(t_info *info, char **tab)
{
  int	i;
  int	fetched;
  char	*cuted;

  if (tab[1] == NULL)
    aff_local(info);
  else
    {
      i = 1;
      while (tab[i] != NULL)
	{
	  if ((is_here(tab[i], '=')) == HERE)
	    cuted = cut_to_equal(tab[i], where_is_equal(tab[i]));
	  else
	    cuted = tab[i];
	  if ((fetched = fetch_env_int(info->set, cuted, "\t")) != -1)
	    update_local(info, tab[i], fetched);
	  else if ((add_local(info, tab[i])) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  i++;
	}
    }
  return (EXIT_SUCCESS);
}

int	aff_local(t_info *info)
{
  int	i;

  i = 0;
  while (info->set[i] != NULL)
    {
      my_printf("%s\n", info->set[i]);
      i++;
    }
  return (EXIT_SUCCESS);
}
