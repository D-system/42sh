/*
** my_memset.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:23:33 2008 thomas brennetot
** Last update Mon May 26 18:10:35 2008 laurent lefebvre
*/

#include "../42.h"

void	*my_memset(void *b, int c, uint size)
{
  uchar	*buff;

  if (b != NULL)
    {
      buff = (unsigned char *)b;
      c = (unsigned char)c;
      while (size--)
        *(buff++) = c;
    }
  return (b);
}
