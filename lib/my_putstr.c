/*
** my_putstr.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:44:28 2008 thomas brennetot
** Last update Thu May 15 12:11:16 2008 thomas brennetot
*/

#include "../42.h"
#include <unistd.h>
#include <stdlib.h>

int	my_putstr(char *str)
{
  xwrite(1, str, my_strlen(str));
  return (EXIT_SUCCESS);
}
