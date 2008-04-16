/*
** my_c.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf/option
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Dec 24 16:51:21 2007 thomas brennetot
** Last update Fri Dec 28 16:38:52 2007 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_printf_c(char *str, va_list *args)
{
  char	c;

  c = va_arg(*args, int);
  write(1, &c, 1);
  str++;
  return;
}
