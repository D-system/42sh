/*
** shell.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:31:09 2008 laurent lefebvre
** Last update Mon May 26 17:43:52 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Boucle de read. Envoie des instructions a gere pour traitement
*/

int	loop(t_info *info)
{
  char	*str;

  while (42)
    {
      prompt(info);
      if ((str = get_next_line(0)) == NULL)
	{
	  if (isatty(0) == 1 && isatty(1) == 1)
	    my_printf("exit\n");
	  return (EXIT_EXIT);
	}
      if (my_strlen(str) > 0)
	{
	  add_event(info, str);
	  if (parse_str(info, str) == EXIT_SUCCESS)
	    if (gere(info, str, FATHER) == EXIT_EXIT)
	      return (EXIT_SUCCESS);
	}
      xfree(str);
    }
  return (EXIT_SUCCESS);
}
