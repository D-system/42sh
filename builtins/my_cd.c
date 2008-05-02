/*
** my_cd.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/builtins
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 30 12:02:44 2008 thomas brennetot
** Last update Fri May  2 19:54:06 2008 thomas brennetot
*/

#include <stdlib.h>
#include <unistd.h>
#include "../42.h"

void	update_pwd(t_info *info, char *str)
{
/*   debug("\n\nFaut mettre a jour le pwd de l'env\n\n"); */
}

int	my_cd_access(t_info *info, char **tab)
{
  if (access(tab[1], F_OK) != -1)
    {
      if (access(tab[1], R_OK) != -1)
	{
	  if (chdir(tab[1]) == -1)
	    {
	      my_printf("%E", "Error for use chdir (change directory)\n");
	      return (EXIT_FAILURE);
	    }
	  else
	    update_pwd(info, tab[1]);
	}
      else
	{
	  my_printf("%E%E", tab[1], ": Permission denied.\n");
	  return (EXIT_FAILURE);
	}
    }
  else
    {
      my_printf("%E%E", tab[1], ": No such file or directory.\n");
      return (EXIT_FAILURE);
    }
  info->last_status = EXIT_SUCCESS;
  return (EXIT_SUCCESS);
}

int	my_cd_nb_arg_n_tild(t_info *info, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if (i > 2)
    {
      my_printf("%E", "cd: Too many arguments.\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	my_cd_tild(t_info *info, char **tab)
{
  char	*home;
  char	*concat;

  if ((home = fetch_env(info->env, "HOME")) == NULL)
    {
      info->last_status = EXIT_FAILURE;
      my_printf("%E", "cd: No home directory.\n");
      return (EXIT_FAILURE);
    }
  concat = my_strcat(home + 5, tab[1] + 1);
  xfree(tab[1]);
  tab[1] = concat;
  if (my_cd_access(info, tab) == EXIT_FAILURE)
    {
      info->last_status = EXIT_FAILURE;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	my_cd(t_info *info, char **tab)
{
  char	*home;
  char	*tab_home[2];

  info->last_status = EXIT_FAILURE;
  if (my_cd_nb_arg_n_tild(info, tab) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if (tab[1] != NULL)
    {
      if (tab[1][0] == '~')
	return (my_cd_tild(info, tab));
      else
	return (my_cd_access(info, tab));
    }
  else
    {
      if ((home = fetch_env(info->env, "HOME")) != NULL)
	{
	  tab_home[1] = home + 5;
	  return (my_cd_access(info, tab_home));
	}
      else
	{
	  my_printf("%E", "cd: No home directory.\n");
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
