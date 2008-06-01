/*
** my_unset.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May 30 17:08:04 2008 aymeric derazey
** Last update Sun Jun  1 06:49:10 2008 aymeric derazey
*/

#include "42.h"

int	my_unset(t_info *info, char **tab)
{
  int	i;

  if (tab[1] == NULL)
    {
      my_printf("%E", "unset: Too few arguments.\n");
      return (EXIT_SUCCESS);
    }
  if (tab[1][0] == '*')
    {
      unsetall(info);
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

void	unsetall(t_info *info)
{
  free_tab(info->set);
if ((info->set = xmalloc(sizeof(*info->env))) == NULL)
    {
      info->set = NULL;
      return ;
    }
  info->set[0] = NULL;
}

void	unset_just_that(char *str, t_info *info)
{
  int	verif_cmp;
  int	i;
  int	size;

  verif_cmp = 42;
  size = my_strlen(str);
  i = 0;
  while (info->set[i] != NULL && verif_cmp != 0)
    {
      verif_cmp = my_strncmp(str, info->set[i], size);
      i++;
    }
  if (verif_cmp == 0)
    unset_free_n_renew(info, i);
}

void	unset_free_n_renew(t_info *info, int delete_local)
{
  delete_local--;
  xfree(info->set[delete_local]);
  while (info->set[delete_local] != NULL)
    {
      info->set[delete_local] = info->set[delete_local + 1];
      delete_local++;
    }
}
