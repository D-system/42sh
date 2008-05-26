/*
** my_putchar.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:44:14 2008 thomas brennetot
** Last update Thu May 15 12:16:27 2008 thomas brennetot
*/

#include "../42.h"
#include <unistd.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  xwrite(1, &c, 1);
  return (EXIT_SUCCESS);
}
