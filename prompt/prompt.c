/*
** prompt.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Fri Apr  4 17:28:39 2008 laurent lefebvre
** Last update Tue Apr 15 15:07:38 2008 aymeric derazey
*/

#include <stdlib.h>
#include "../42.h"

/*
** Affiche le prompt, gestion de l'isatty
*/

int	prompt(t_info *info)
{
  int	i;
  int	var;

  if (info->prompt == NULL)
    my_putchar('>');
  else
    {
      i = 0;
      while (info->prompt[i] != '\0')
	{
	  var = 0;
	  while (info->prompt[i + var] != '%' && info->prompt[i + var] != '\0')
	    var++;
	  write(1, &info->promtp[i], var);
	  i += (var + 1);
	  if (info->prompt[i] == '%')
	    if (launch_fct(info, i) == EXIT_SUCCESS)
	      i++;
	}
    }
  return (EXIT_SUCCESS);
}
