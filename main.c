/*
** main.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
** Last update Sat Apr 12 15:45:58 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

int		main(void)
{
  extern char	**environ;
  t_info	info;


  if (init(environ, &info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  info.prompt = "Laurent est un pedophile @ $(HOST)>";
  if (loop(&info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /*freeall();*/
  return (EXIT_SUCCESS);
}
