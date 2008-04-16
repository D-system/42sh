/*
** my_S.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Fri Dec 28 16:42:50 2007 thomas brennetot
** Last update Wed Apr 16 14:57:54 2008 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_invisiblechar_in_octal(char c)
{
  my_putchar('\\');
  my_putchar('0');
  my_putnbr_base(c, "01234567");
  return;
}

void	my_printf_S(char *str, va_list *args)
{
  int	i;
  char	*str2;

  i = 0;
  str2 = va_arg(*args, char*);
  while (str2[i] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	write(1, &str2[i], 1);
      else
	my_invisiblechar_in_octal(str[i]);
      i++;
    }
  str++;
  return;
}
