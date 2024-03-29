/*
** prompt.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
**
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
**
** Started on  Fri Apr  4 17:28:39 2008 laurent lefebvre
** Last update Fri May 30 18:41:26 2008 aymeric derazey
*/

#include <stdlib.h>
#include <unistd.h>
#include "42.h"

/*
** Affiche le prompt, gestion de l'isatty
*/

void	prompt(t_info *info)
{
  int	i;
  int	var;
  char	*prompt;

  if (isatty(1) == 0 || isatty(0) == 0)
    return ;
  info->size_prompt = 2;
  prompt = fetch_env(info->set, "prompt", "\t");
  if (prompt == NULL)
    my_putstr("> ");
  else
    {
      i = 0;
      prompt += 7;
      while (prompt[i] != '\0')
	{
	  var = 0;
	  while (prompt[i + var] != '%' && prompt[i + var] != '\0')
	    var++;
	  if (var > 0)
	    xwrite(1, &prompt[i], var);
	  i += var;
	  if (prompt[i] == '%')
	    if (launch_fct(info, ++i, prompt) == EXIT_SUCCESS)
	      i++;
	}
    }
}
