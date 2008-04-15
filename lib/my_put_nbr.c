/*
** my_put_nbr.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:43:43 2008 thomas brennetot
** Last update Mon Mar 31 17:21:06 2008 thomas brennetot
*/

#include "../42.h"

void	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      my_put_nbr(-nb);
    }
  else
    {
      if (nb < 10)
	my_putchar(nb + '0');
      else
	{
	  my_put_nbr(nb / 10);
	  my_putchar((nb % 10) + '0');
	}
    }
  return;
}
