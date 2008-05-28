/*
** fetch_env.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/damax
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Apr  7 18:55:39 2008 thomas brennetot
** Last update Wed May 28 17:18:48 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

/*
** donne un pointeur sur l'environement demande
*/

char	*fetch_env(char **env, char *str, char *sepa)
{
  int	i;
  int	size;
  char	*str_cat;

  i = 0;
  if (env == NULL)
    return (NULL);
  if (env[i] == NULL)
    return (NULL);
  if ((str_cat = my_strcat(str, sepa)) == NULL)
    return (NULL);
  size = my_strlen(str_cat);
  while (my_strncmp(env[i], str_cat, size) != 0)
    {
      i++;
      if (env[i] == NULL)
	{
	  xfree(str_cat);
	  return (NULL);
	}
    }
  xfree(str_cat);
  return (env[i]);
}
