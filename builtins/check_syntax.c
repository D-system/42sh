/*
** check_syntax.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May  8 17:51:11 2008 aymeric derazey
** Last update Wed May 28 17:58:14 2008 aymeric derazey
*/

#include "42.h"

/*
** check les erreurs de syntax avec la commande set
*/

int	check_syntax(t_info *info, char **tab)
{
  int	i;

  i = 1;
  while (tab[i] != NULL)
    {
      if ((check_begin(info, tab[i]) == EXIT_FAILURE))
	return (EXIT_FAILURE);
      if ((check_equal(info, tab[i]) == EXIT_FAILURE))
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}


/*
** check une erreur au debut de l'argument pris en parametre, celui-ci doit commencer
** par une lettre.
*/

int	check_begin(t_info *info, char *str)
{
  if (str == NULL)
    return (EXIT_FAILURE);
  if (!((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z')))
    {
      my_printf("set: Variable name must begin with a letter.\n");
      return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}

/*
** chercher si oui ou non il a un signe "="
** non -> error syntax.
*/

int	check_equal(t_info *info, char *str)
{
  int	i;
  int	flag;

  if (str == NULL)
    return (EXIT_FAILURE);
  flag = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	flag++;
      i++;
    }
  if (flag == 1)
    {
      my_printf("set: Syntax Error\n");
      return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}
