/*
** xopen.c for minishell3 in /u/epitech_2012/deraze_a/cu/rendu/c/minishell3/lib
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat Mar 15 16:17:42 2008 aymeric derazey
** Last update Sat May 24 12:43:40 2008 nicolas mondange
*/

#include <fcntl.h>
#include "../42.h"

int	xopen(char *file, int flags)
{
  int	fd;

  if ((fd = open(file, flags, 0644)) == -1)
    my_printf("%E%E%E", "Error while opening \"", file, "\"\n");
  return (fd);
}
