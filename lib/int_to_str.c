/*
** putnbr_buffer.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/lib
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Tue May 27 14:43:30 2008 aymeric derazey
** Last update Fri May 30 00:02:44 2008 aymeric derazey
*/

#include "42.h"

int	int_len(int nb)
{
  int	i;

  i = 0;
  while (nb != 0)
    {
      nb /= 10;
      i++;
    }
  return (i);
}

char	*int_to_str(int nb)
{
  char	*buff;
  int	i;
  int	div;
  int	len;

  div = 1;
  len = int_len(nb);
  buff = xmalloc(sizeof(*buff) * (len + 1));
  while (len > 1)
    {
      div *= 10;
      len--;
    }
  i = 0;
  len = int_len(nb);
  while (len > 1)
    {
      buff[i] = (nb / div) % 10 + '0';
      div = div / 10;
      i++;
      len--;
    }
  buff[i++] = (nb % 10) + '0';
  buff[i] = '\0';
  return (buff);
}
