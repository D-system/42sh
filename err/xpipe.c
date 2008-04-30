/*
** xpipe.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun Apr 27 13:55:18 2008 thomas brennetot
** Last update Wed Apr 30 11:54:27 2008 thomas brennetot
*/

#include <unistd.h>
#include <stdlib.h>
#include "../42.h"

int	xpipe(int *fildes)
{
  int	value;

  value = pipe(fildes);
  if (value != 0)
    {
      my_printf("%E", "Problem with pipe function\nx");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
