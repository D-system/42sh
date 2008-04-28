/*
** gere_dotcoma.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:42:30 2008 laurent lefebvre
** Last update Mon Apr 28 10:53:25 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** gestion en recursif des ";"
*/

int	gere_dotcoma_put_zero(char *str)
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
	{
	  str[i] = '\0';
	  return (i);
	}
      if (str[i] == ')')
	bracket--;
      i++;
    }
  return (-1); /* pas de EXIT_FAILURE car il vaut 1 donc une longeur */
}

int	gere_dotcoma(t_info *info, char *str, int flag)
{
  int	i;

  debug("c'est quoi le prob %s\n", str);
  if ((i = gere_dotcoma_put_zero(str)) == -1)
    return (EXIT_FAILURE);
  gere_redirect(info, str, flag);
  gere_redirect(info, str + i + 1, flag);
  return (EXIT_SUCCESS);
}
