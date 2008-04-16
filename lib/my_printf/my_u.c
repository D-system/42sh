/*
** my_u.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Tue Dec 25 19:00:03 2007 thomas brennetot
** Last update Fri Dec 28 16:41:07 2007 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void		my_put_nbr_u(unsigned int nb)
{
  if (nb < 10)
    my_putchar(nb + '0');
  else
    {
      my_put_nbr(nb/10);
      my_putchar((nb%10) + '0');
    }
  return;
}

void		my_printf_u(char *str, va_list *args)
{
  unsigned int	nb;

  nb = va_arg(*args, unsigned int);
  my_put_nbr_u(nb);
  str++;
  return;
}
