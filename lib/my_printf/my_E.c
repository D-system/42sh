/*
** my_E.c for  in /u/epitech_2012/brenne_t/cu/rendu/test/minishell2/current
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Thu Mar 13 11:49:51 2008 thomas brennetot
** Last update Thu Mar 13 12:53:49 2008 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_printf_E(char *str, va_list *args)
{
  char	*str2;

  str2 = va_arg(*args, char*);
  write(2, str2, my_strlen(str2));
  str++;
  return;
}

void	my_printf_e(char *str, va_list *args)
{
  int	c;

  c = va_arg(*args, int);
  write(2, &c, 1);
  str++;
  return;
}
