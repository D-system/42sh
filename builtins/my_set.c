/*
** my_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  2 22:12:11 2008 aymeric derazey
** Last update Wed May  7 11:23:01 2008 thomas brennetot
*/

#include "../42.h"



/* int	my_set(t_info *info, char **tab) */
/* { */
/*   int	i; */

/*   if (tab[1] == NULL) */
/*     aff_set(info); */
/*   else */
/*     { */
/*       if (info->set[0] == NULL || fetch_env(info->set, tab[1]) == NULL) */
/* 	add_set(info, tab); */
/*       else */
/* 	update_env(info, tab); */
/*     } */
	  
/*    return (EXIT_SUCCESS); */
/* } */
int	my_set(t_info *info, char **tab)
{
  if (tab[1] == NULL)
    aff_set(info);
  else
    return (EXIT_SUCCESS);
  return (EXIT_SUCCESS);
}

int	aff_set(t_info *info)
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
