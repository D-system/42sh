/*
** main.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
** Last update Thu May 29 19:02:10 2008 nicolas mondange
*/

#include <stdlib.h>
#include "42.h"

int		main(void)
{
  extern char	**environ;
  t_info	info;

  if (init(environ, &info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  info.prompt = my_strdup("(%n@%M 42sh)"); /* On set en dur pour l'instant */
  loop(&info);
  save_event(&info);
  freeall();
  return (EXIT_SUCCESS);
}
