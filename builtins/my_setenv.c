/*
** my_setenv.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/builtins
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 30 16:02:32 2008 thomas brennetot
** Last update Thu May  8 17:52:40 2008 aymeric derazey
*/

#include <stdlib.h>
#include "../42.h"

char	*add_env_concat(char **tab, int mode)
{
  int	istr;
  int	itab;
  char	*str_tmp;

  if (mode == 3)
    str_tmp = xmalloc(sizeof(*str_tmp) * (my_strlen(tab[1]) + my_strlen(tab[2]) + 2));
  else
    str_tmp = xmalloc(sizeof(*str_tmp) * (my_strlen(tab[1]) + 2));
  istr = 0;
  itab = 0;
  while (tab[1][itab] != '\0')
    str_tmp[istr++] = tab[1][itab++];
  str_tmp[istr++] = '=';
  itab = 0;
  if (mode == 3)
    while (tab[2][itab] != '\0')
      str_tmp[istr++] = tab[2][itab++];
  str_tmp[istr] = '\0';
  return (str_tmp);
}

void	add_env(t_info *info, char **tab, int nb_env)
{
  int	i;
  char	**env_tmp;

  i = 0;
  while (info->env[i] != NULL)
    i++;
  if ((env_tmp = xmalloc(sizeof(*env_tmp) * (i + 2))) == NULL)
    return ;
  i = 0;
  while (info->env[i] != NULL)
    {
      env_tmp[i] = info->env[i];
      i++;
    }
  if (nb_env == 3)
    env_tmp[i++] = add_env_concat(tab, 3);
  else
    env_tmp[i++] = add_env_concat(tab, 2);
  env_tmp[i] = NULL;
  free(info->env);
  info->env = env_tmp;
}

void	update_env(t_info *info, char **tab, int nb_env)
{
  int	ienv;
  int	size;
  char	*tmp;

  ienv = 0;
  size = my_strlen(tab[1]);
  while (my_strncmp(info->env[ienv], tab[1], size) != 0)
    ienv++;
  tmp = info->env[ienv];
  if (nb_env == 3)
    info->env[ienv] = add_env_concat(tab, 3);
  else
    info->env[ienv] = add_env_concat(tab, 2);
  xfree(tmp);
}

int	my_setenv(t_info *info, char **tab)
{
  int	nb_env;

  nb_env = 0;
  while (tab[nb_env] != NULL)
    nb_env++;
  if (nb_env == 1)
    my_env(info, tab);
  else if (nb_env > 3)
    my_printf("%E", "setenv: Too many arguments.\n");
  else
    {
      if (info->env[0] == NULL || fetch_env(info->env, tab[1], "=") == NULL)
	add_env(info, tab, nb_env);
      else
	update_env(info, tab, nb_env);
    }
  return (EXIT_SUCCESS);
}
