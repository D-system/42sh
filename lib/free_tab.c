/*
** free_tab.c for  in /u/epitech_2012/brenne_t/cu/rendu/test/minishell/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Feb 27 11:52:06 2008 thomas brennetot
** Last update Tue May 27 19:23:57 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

void	free_tab(char **tab)
{
  int	i;

  if (tab == NULL)
    return ;
  i = 0;
  while (tab[i] != NULL)
    {
      xfree(tab[i]);
      i++;
    }
  xfree(tab);
}
