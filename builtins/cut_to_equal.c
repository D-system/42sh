/*
** cut_to_equal.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Thu May 29 13:28:16 2008 aymeric derazey
** Last update Thu May 29 16:05:02 2008 aymeric derazey
*/

#include "42.h"

/*
** si il y'a un '=' dans la str la
** fonction copie les char jusqu'au '='
*/

char	*cut_to_equal(char *str, int count)
{
  char	*buff;

  buff = xmalloc(sizeof(*buff) * count+1);
  buff = my_strncpy(buff, str, count);
  return (buff);
}

/*
** Compte combien de caracteres il y a avant le premier '='
*/

int	where_is_equal(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '=')
    i++;
  return (i);
}

/*
** check si il ya le caractere c dans la str
*/

int	is_here(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (HERE);
      i++;
    }
  return (NOT_HERE);
}
