/*
** xdup2.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun Apr 27 18:54:16 2008 thomas brennetot
** Last update Tue May 27 19:33:29 2008 aymeric derazey
*/

#include <stdlib.h>
#include <unistd.h>
#include "42.h"

int	xdup2(int old_fd, int new_fd)
{
  if (dup2(old_fd, new_fd) == -1)
    {
      my_printf("%E", "Problem for dup a fd\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
