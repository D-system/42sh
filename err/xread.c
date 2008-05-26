/*
** xread.c for minishell3 in /u/epitech_2012/deraze_a/cu/rendu/c/minishell3/lib
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat Mar 15 16:17:55 2008 aymeric derazey
** Last update Sat May 24 12:42:21 2008 nicolas mondange
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "../42.h"

int	xread(int fd, char *buf, int size)
{
  int	nb;

  if ((nb = read(fd, buf, size)) == -1)
    my_printf("%E", "error while reading file\n");
  return (nb);
}
