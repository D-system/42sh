/*
** shell.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:31:09 2008 laurent lefebvre
** Last update Tue Apr 15 17:39:44 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Boucle de read. Envoie des instructions a gere_redirect pour traitement
*/

int	loop(t_info *info)
{
  int	nb_read;
  char	buffer[BUFF_SIZE];
  
  if (prompt(info) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  while ((nb_read = xread(0, buffer, BUFF_SIZE - 1)) != 0)
    {
      my_memset(buffer, 0, BUFF_SIZE);
      if (prompt(info) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
/*   gere_redirect(); */
  return (EXIT_SUCCESS);
}
