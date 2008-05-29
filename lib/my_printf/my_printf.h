/*
** my_printf.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/my_printf
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Tue Nov 13 14:41:34 2007 thomas brennetot
** Last update Thu May 29 10:58:14 2008 laurent lefebvre
*/

#ifndef __MY_PRINTF_H__
#define __MY_PRINTF_H__

#include <stdarg.h>
#include "42.h"

typedef struct	opt_s
{
  char		c;
  void		(*fonction)();
}		opt_t;

int	my_printf(char *print_str, ...);
void	choose_fonction(va_list *args, char *str, int *i);
void	my_printf_c(char *str, va_list *args);
void	my_printf_s(char *str, va_list *args);
void	my_printf_S(char *str, va_list *args);
void	my_printf_d(char *str, va_list *args);
void	my_printf_p(char *str, va_list *args);
void	my_printf_P(char *str, va_list *args);
void	my_printf_o(char *str, va_list *args);
void	my_printf_x(char *str, va_list *args);
void	my_printf_X(char *str, va_list *args);
void	my_printf_modu(char *str, va_list *args);
void	my_printf_u(char *str, va_list *args);
void	my_printf_E(char *str, va_list *args);
void	my_printf_e(char *str, va_list *args);
void	my_put_ptr_adr(unsigned int adr, int flag);
void	my_put_nbr_u(unsigned int nb);

#endif
