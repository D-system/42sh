/*
** my_putchar.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:44:14 2008 thomas brennetot
** Last update Mon Apr  7 15:12:39 2008 laurent lefebvre
*/

#include "../42.h"
#include <unistd.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  if (c >= '\0' && c < 128)
    {
      if (xwrite(1, &c, 1) == -1)
	return (EXIT_FAILURE);
    }
  else
    {
      my_putstr("my_putchar failed, bad character\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
