/*
** main.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
** Last update Mon May 26 18:01:41 2008 laurent lefebvre
*/

#include <stdlib.h>
#include "42.h"

int		main(void)
{
  extern char	**environ;
  t_info	info;
  int		value;
  
  if (init(environ, &info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  info.prompt = my_strdup("%n@%M >>%?<< 42sh ##>"); /* On set en dur pour l'instant */
  value = loop(&info);
  save_event(&info);
  freeall();
  return (value);
}
