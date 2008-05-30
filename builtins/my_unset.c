/*
** my_unset.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May 30 17:08:04 2008 aymeric derazey
** Last update Fri May 30 17:32:43 2008 aymeric derazey
*/

#include "42.h"

int	my_unset(t_info *info, char **tab)
{
  int	i;

  if (tab[1][0] == '*')
    {
      my_unsetall(info);
      return (EXIT_SUCCESS);
    }
  else
    {
      i = 1;
      while (tab[i] != NULL)
	{
	  unset_just_that(tab[i], info);
	  i++;
	}
    }
  return (EXIT_SUCCESS);
}
