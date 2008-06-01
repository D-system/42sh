/*
** xchdir.c for  in /u/epitech_2012/lefebv_l/cu/public/42sh/lefebv_l
**
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
**
** Started on  Tue May 27 17:54:33 2008 laurent lefebvre
** Last update Sun Jun  1 06:55:09 2008 thomas brennetot
*/

#include "42.h"

int	xchdir(const char *path)
{
  if (chdir(path) == 0)
    return (0);
  my_printf("%E", "chdir failed\n");
  return (-1);
}
