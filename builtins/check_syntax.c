/*
** check_syntax.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May  8 17:51:11 2008 aymeric derazey
** Last update Sun Jun  1 06:53:35 2008 thomas brennetot
*/

#include "42.h"

/*
** check les erreurs de syntax avec la commande set
*/

int	check_syntax(t_info *info, char *str, char **new_local)
{
  if ((check_begin(info, str) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  if ((check_equal(info, str, new_local) == EXIT_FAILURE))
    return (EXIT_FAILURE);
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
      my_printf("%E", "set: Variable name must begin with a letter.\n");
      return (status(info, EXIT_FAILURE));
    }
  return (EXIT_SUCCESS);
}

/*
** ajoute la chaine de caractere str au tableau **set
** selon si il y a un '=' ou non.
*/

int	check_equal(t_info *info, char *str, char **new_local)
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
  if (flag >= 1)
    add_with_equal(info, str, new_local);
  else
    add_without_equal(info, str, new_local);
  return (EXIT_SUCCESS);
}
