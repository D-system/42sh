/*
** my_memcpy.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Mar 31 17:23:33 2008 thomas brennetot
** Last update Wed May 28 17:50:48 2008 thomas brennetot
*/

#include "42.h"

void	*my_memcpy(void *dest, void *src, int size)
{
  int	i;
  char	*dest2;
  char	*src2;

  dest2 = dest;
  src2 = src;
  i = 0;
  while (i != size)
    {
      dest2[i] = src2[i];
      i++;
    }
  return (dest2);
}
