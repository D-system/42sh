/*
** gere_dotcoma.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:42:30 2008 laurent lefebvre
** Last update Sun Apr 27 12:46:27 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** gestion en recursif des ";"
*/

int	gere_dotcoma_bracket(char *str)
{
  int	bracket;
  int	i;

  i = 0;
  bracket = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	bracket++;
      if (bracket == 0 && str[i] == ';')
	return (i);
      if (str[i] == ')')
	bracket--;
      i++;
    }
  return (i);
}

int	gere_dotcoma(t_info *info, char *str)
{
  int	i;

  i = gere_dotcoma_bracket(str);
  if (str[i] != ';')
    return (EXIT_FAILURE);
  str[i] = '\0';
  gere_redirect(info, str);
  gere_redirect(info, str + i + 1);
  return (EXIT_SUCCESS);
}
