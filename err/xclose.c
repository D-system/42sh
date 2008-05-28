/*
** xclose.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun Apr 27 18:49:37 2008 thomas brennetot
** Last update Tue May 27 19:33:21 2008 aymeric derazey
*/

#include <stdlib.h>
#include <unistd.h>
#include "42.h"

int	xclose(int fd)
{
  if (close(fd) == -1)
    {
      my_printf("%E", "Problem for close a fd\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
