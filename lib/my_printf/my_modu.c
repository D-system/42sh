/*
** my_printf_c_s_d.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun Dec 23 18:44:52 2007 thomas brennetot
** Last update Fri Dec 28 16:42:01 2007 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

void	my_printf_modu(char *str, va_list *args)
{
  write(1, "%", 1);
  str++;
  args++;
  return;
}
