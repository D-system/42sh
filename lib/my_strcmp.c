/*
** my_strcmp.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:46:55 2008 thomas brennetot
** Last update Tue May 27 19:28:03 2008 aymeric derazey
*/

#include "42.h"
#include <stdlib.h>

int	my_strcmp(char *s1, char *s2)
{
  int i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	{
	  if (s1[i] > s2[i])
	    return (1);
	  else
	    return (-1);
	}
      i++;
    }
  return (0);
}
