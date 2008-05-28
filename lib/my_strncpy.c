/*
** my_strncpy.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:49:12 2008 thomas brennetot
** Last update Tue May 27 19:28:48 2008 aymeric derazey
*/

#include "42.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (n--)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
