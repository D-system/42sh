/*
** my_d.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf/option
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Dec 24 16:53:45 2007 thomas brennetot
** Last update Fri Dec 28 16:39:10 2007 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_printf_d(char *str, va_list *args)
{
  int	nb;

  nb = va_arg(*args, int);
  my_put_nbr(nb);
  str++;
  return;
}
