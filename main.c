/*
** main.c for  in /u/epitech_2012/lefebv_l/public/42sh/official
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 17:20:16 2008 thomas brennetot
<<<<<<< .mine
** Last update Wed Apr 16 15:29:22 2008 thomas brennetot
=======
** Last update Wed Apr 16 15:27:44 2008 nicolas mondange
>>>>>>> .r12
*/

#include <stdlib.h>
#include "42.h"

int		main(void)
{
  extern char	**environ;
  t_info	info;

  if (init(environ, &info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  info.prompt = "%n@%d>";
  if (loop(&info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  /*freeall();*/
  return (EXIT_SUCCESS);
}
