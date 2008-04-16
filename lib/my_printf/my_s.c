/*
** my_s.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf/option
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Dec 24 16:52:09 2007 thomas brennetot
** Last update Fri Dec 28 16:40:44 2007 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_printf_s(char *str, va_list *args)
{
  char	*str2;

  str2 = va_arg(*args, char*);
  write(1, str2, my_strlen(str2));
  str++;
  return;
}
