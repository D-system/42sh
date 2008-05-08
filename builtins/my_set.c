/*
** my_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  2 22:12:11 2008 aymeric derazey
** Last update Thu May  8 16:51:00 2008 aymeric derazey
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
 /*  else */
/*     { */
/*       if ((info->set[0] == NULL) || (fetch_env(info->set, tab[1], "\t")) == NULL) */
/* 	add_local(info, tab); */
/*       else */
/* 	    update_local(info, tab);  */
/*       return (EXIT_SUCCESS); */
/*     } */
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
