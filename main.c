/*
** main.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Fri May 30 00:34:15 2008 aymeric derazey
** Last update Fri May  8 20:46:05 2009 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

int		main(void)
{
  extern char	**environ;
  t_info	info;

  init(environ, &info);
  loop(&info);
  save_event(&info);
  freeall();
  return (EXIT_SUCCESS);
}
