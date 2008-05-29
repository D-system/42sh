/*
** shell.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:31:09 2008 laurent lefebvre
** Last update Wed May 28 21:23:12 2008 nicolas mondange
*/

#include <stdlib.h>
#include "42.h"

/*
** Boucle de read. Envoi des instructions a gere pour traitement
*/

void	loop(t_info *info)
{
  char	*str;
  
  while (42)
    {
      prompt(info);
      if (isatty(0) == 1 && isatty(1) == 1)
	{
	  if ((str = gere_keyboard(info)) == NULL)
	    {
	      my_printf("exit\n");
	      return ;
	    }
	}
      else if ((str = get_next_line(0)) == NULL)
	return ;
      if (my_strlen(str) > 0)
	{
	  add_event(info, str);
	  if (parse_str(info, str) == EXIT_SUCCESS)
	    if (gere(info, str, FATHER) == EXIT_EXIT)
	      return ;
	}
      xfree(str);
    }
}


