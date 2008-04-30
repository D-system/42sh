/*
** my_unsetenv.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/builtins
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 30 16:10:38 2008 thomas brennetot
** Last update Wed Apr 30 16:15:43 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

void	unsetenv_free_n_renew(t_info *info, int delete_env)
{
  int	ienv;

  ienv = delete_env;
  while (info->env[ienv] != NULL)
    {
      info->env[ienv] = info->env[ienv + 1];
      ienv++;
    }
}

void	unsetenv_just_that(char **tab, t_info *info)
{
  int	itab;
  int	ienv;
  int	verif_cmp;
  int	size;

  itab = 1;
  while (tab[itab] != NULL)
    {
      ienv = 0;
      verif_cmp = 42;
      size = my_strlen(tab[itab]);
      while (info->env[ienv] != NULL && verif_cmp != 0)
	{
	  verif_cmp = my_strncmp(tab[itab], info->env[ienv], size);
	  if (verif_cmp != 0)
	    ienv++;
	}
      if (verif_cmp == 0)
	unsetenv_free_n_renew(info, ienv);
      itab++;
    }
}

void	unsetenv_all(t_info *info)
{
  free_tab(info->env);
  if ((info->env = xmalloc(sizeof(*info->env))) == NULL)
    {
      info->env = NULL;
      return ;
    }
  info->env[0] = NULL;
}

int	my_unsetenv(t_info *info, char **tab)
{
  int	itab;
  int	nb_args;

  nb_args = 0;
  while (tab[nb_args] != NULL)
    nb_args++;
  if (nb_args == 1)
    {
      info->last_status = EXIT_FAILURE;
      my_printf("%E", "unsetenv: Too few arguments.\n");
      return (EXIT_FAILURE);
    }
  else
    {
      itab = 1;
      while (tab[itab] != NULL)
	{
	  if (my_strncmp(tab[itab++], "*", 1) == 0)
	    {
	      unsetenv_all(info);
	      return (EXIT_SUCCESS);
	    }
	}
      unsetenv_just_that(tab, info);
    }
  return (EXIT_SUCCESS);
}
