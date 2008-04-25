/*
** shell.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:31:09 2008 laurent lefebvre
** Last update Thu Apr 24 15:07:16 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Boucle de read. Envoie des instructions a gere_redirect pour traitement
*/

int	loop(t_info *info)
{
  char	str[BUFF_COMPL];

  while (42)
    {
      prompt(info);
      completion(info, str);
      if (str != NULL)
	{
	  if (parse_str(info, str) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
