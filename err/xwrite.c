/*
** xwrite.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/err
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:55:00 2008 thomas brennetot
** Last update Fri Apr  4 17:08:22 2008 laurent lefebvre
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../42.h"

int		xwrite(int fd, char *str, int size)
{
  static int	verif = 0;
  
  if (verif != -1)
    verif = write(fd, str, size);
  else
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
