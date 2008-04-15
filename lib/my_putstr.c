/*
** my_putstr.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:44:28 2008 thomas brennetot
** Last update Fri Apr  4 17:05:32 2008 laurent lefebvre
*/

#include "../42.h"
#include <unistd.h>
#include <stdlib.h>

int	my_putstr(char *str)
{
  int	i;
  
  i = 0;
  while (str[i] != '\0')
    {
      if (my_putchar(str[i]) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      i++;
    }
  return (EXIT_SUCCESS);
}
