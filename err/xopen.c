/*
** xopen.c for minishell3 in /u/epitech_2012/deraze_a/cu/rendu/c/minishell3/lib
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat Mar 15 16:17:42 2008 aymeric derazey
** Last update Mon Mar 31 17:39:23 2008 aymeric derazey
*/

#include <fcntl.h>
#include "../42.h"

int	xopen(char *file)
{
  int	fd;
  if ((fd = open(file, O_RDONLY)) == -1)
    my_putstr("error while opening file\n");
  return (fd);
}
