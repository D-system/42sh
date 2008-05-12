/*
** check_syntax.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu May  8 17:51:11 2008 aymeric derazey
** Last update Sun May 11 17:19:29 2008 aymeric derazey
*/

#include "../42.h"

/*
** check les erreurs de syntax avec la commande set
*/

int	check_syntax(t_info *info, char **tab, char **new_local)
{
  int	i;
  int	j;

  j = 0;
  while (info->set[j] != NULL)
    j++;
  i = 0;
  while (tab[i] != NULL)
    {
      if ((check_begin(info, tab[i])) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      /*      else if ((check_equal(info, tab[i])) == EXIT_FAILURE)
	      return (EXIT_FAILURE); */
      else
	new_local[j++] = add_local_concat(tab[i]);
      i++;
    }
  new_local[j] = NULL;
  free(info->env);
  info->env = new_local;
  return (EXIT_SUCCESS);
}

/* 
** check une erreur au debut de l'argument pris en parametre, celui-ci doit commencer
** par une lettre.
*/

int	check_begin(t_info *info, char *str)
{
  if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z'))
    {
      my_putstr("set: Variable name must begin with a letter.");
      return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}

/*
** chercher si oui ou non il a un signe "="
** si non -> error syntax.
*/

int	check_equal(t_info *info, char *tab)
{
  int	i;
  int	flag;

  flag = 0;
  i = 0;
  while (tab[i] != '\0')
    {
      if (tab[i] == '=')
	flag++;
      i++;
    }
  if (flag == 1)
    {
      my_putstr("set: Syntax Error\n");
      return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}
