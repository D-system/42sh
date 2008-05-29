/*
** update_check_syntax.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Wed May 28 22:48:20 2008 aymeric derazey
** Last update Thu May 29 17:21:56 2008 aymeric derazey
*/

#include "42.h"

/*
** check les erreurs de syntax avec la commande set
*/

int	up_check_syntax(t_info *info, char *str, int fetched)
{
  if ((check_begin(info, str) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  if ((up_check_equal(info, str, fetched) == EXIT_FAILURE))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

/*
** ajoute la chaine de caractere str au tableau **set
** selon si il y a un '=' ou non.
*/

int	up_check_equal(t_info *info, char *str, int fetched)
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
    update_with_equal(info, str, fetched);
  else
    update_without_equal(info, str, fetched);
  return (EXIT_SUCCESS);
}
