/*
** my_strdup.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:47:38 2008 thomas brennetot
** Last update Tue May 27 19:28:11 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

char	*my_strdup(char *str)
{
  char	*addr;
  int	i;

  i = 0;
  if (str == NULL)
    return (NULL);
  if ((addr = xmalloc((sizeof(*addr) * my_strlen(str)) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      addr[i] = str[i];
      i++;
    }
  addr[i] = '\0';
  return (addr);
}
