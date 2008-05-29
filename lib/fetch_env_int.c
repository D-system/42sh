/*
** fetch_env_int.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Wed May 28 23:33:12 2008 aymeric derazey
** Last update Thu May 29 15:52:01 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

/*
** donne un int sur l'environement demande
*/

int	fetch_env_int(char **env, char *str, char *sepa)
{
  int	i;
  int	size;
  char	*str_cat;

  i = 0;
  if (env == NULL)
    return (-1);
  if (env[i] == NULL)
    return (-1);
  if ((str_cat = my_strcat(str, sepa)) == NULL)
    return (-1);
  size = my_strlen(str_cat);
  while (my_strncmp(env[i], str_cat, size) != 0)
    {
      i++;
      if (env[i] == NULL)
	{
	  xfree(str_cat);
	  return (-1);
	}
    }
  xfree(str_cat);
  return (i);
}
