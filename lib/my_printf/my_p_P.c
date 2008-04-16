/*
** my_put_ptr.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun Dec 23 17:53:32 2007 thomas brennetot
** Last update Fri Dec 28 16:40:29 2007 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_put_ptr_adr(unsigned int adr, int flag)
{
  char		*base;
  char		res[9];
  int		i;

  if (flag == 1)
    base = "0123456789abcdef";
  else
    base = "0123456789ABCDEF";
  i = 8;
  while ((adr / 16) > 0 || i >= 8)
    {
      res[i] = base[(adr % 16)];
      adr /= 16;
      i--;
    }
  res[i] = base[(adr % 16)];
  #if !(solaris)
  write(1, "0x", 2);
  #endif
  while (i < 9)
    write(1, &res[i++], 1);
  return ;
}

void		my_printf_p(char *str, va_list *args)
{
  unsigned int	adr;

  adr = va_arg(*args, unsigned int);
  my_put_ptr_adr(adr, 1);
  str++;
  return;
}

void		my_printf_P(char *str, va_list *args)
{
  unsigned int	adr;

  adr = va_arg(*args, unsigned int);
  my_put_ptr_adr(adr, 2);
  str++;
  return;
}
