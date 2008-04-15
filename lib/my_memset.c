/*
** my_memset.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:23:33 2008 thomas brennetot
** Last update Mon Mar 31 17:23:38 2008 thomas brennetot
*/

#include "../42.h"

void	*my_memset(char *b, char c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      b[i] = c;
      i++;
    }
  return (b);
}
