/*
** prompt.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Fri Apr  4 17:28:39 2008 laurent lefebvre
** Last update Mon May 12 12:59:48 2008 thomas brennetot
*/

#include <stdlib.h>
#include <unistd.h>
#include "../42.h"

/*
** Affiche le prompt, gestion de l'isatty
*/

void	prompt(t_info *info)
{
  int	i;
  int	var;

  if (isatty(1) == 0 || isatty(0) == 0)
    return ;
  if (info->prompt == NULL)
    my_putstr("> ");
  else
    {
      i = 0;
      while (info->prompt[i] != '\0')
	{
	  var = 0;
	  while (info->prompt[i + var] != '%' && info->prompt[i + var] != '\0')
	    var++;
	  if (var > 0)
	    write(1, &info->prompt[i], var);
	  i += var;
	  if (info->prompt[i] == '%')
	    if (launch_fct(info, ++i) == EXIT_SUCCESS)
	      i++;
	}
    }
}
