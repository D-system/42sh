/*
** my_printf.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Tue Nov 13 14:41:34 2007 thomas brennetot
** Last update Fri Apr 25 18:56:03 2008 thomas brennetot
*/

#include <stdarg.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "my_printf.h"

opt_t	pf_gl[] =
  {
    {'c', my_printf_c}, /*my_putchar*/
    {'s', my_printf_s}, /*my_putstr*/
    {'d', my_printf_d}, /*my_put_nbr*/
    {'i', my_printf_d}, /*my_put_nbr*/
    {'%', my_printf_modu}, /*write %*/
    {'p', my_printf_p}, /*my_put_ptr_adr minus*/
    {'P', my_printf_P}, /*my_put_ptr_adr MAJ*/
    {'u', my_printf_u}, /*my_put_nbr_u unsigned int*/
    {'o', my_printf_o}, /*my_putnbr_base octal*/
    {'x', my_printf_x}, /*my_putnbr_base hexa*/
    {'X', my_printf_X}, /*my_putnbr_base HEXA*/
    {'S', my_printf_S}, /*my_putstr & invisible char in octal*/
    {'E', my_printf_E}, /*my_putstr sur la sortie d'erreur*/
    {'e', my_printf_e}, /*my_putchar sur la sortie d'erreur*/
    {0, 0}
  };

void		choose_fonction(va_list *args, char *str, int *i)
{
  int		x;

  x = 0;
  while ((str[(*i)] >= '0' && str[(*i)] <= '9') || str[(*i)] == '.')
    (*i)++;
  while (pf_gl[x].c != 0 || pf_gl[x].c == str[(*i)])
    {
      if (pf_gl[x].c == str[(*i)])
	pf_gl[x].fonction(str + (*i), args);
      x++;
    }
}

int		my_printf(char *str, ...)
{
  int		i;
  va_list	args;

  va_start(args, str);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  i++;
	  choose_fonction(&args, str, &i);
	}
      else
	my_putchar(str[i]);
      i++;
    }
  va_end(args);
  return (0);
}
