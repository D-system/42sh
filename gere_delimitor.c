/*
** gere_delimitor.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Wed Apr 30 11:02:19 2008 thomas brennetot
** Last update Thu May 29 22:18:03 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Lance les fonctions qui 'decoupent' la chaine de caractere.
*/

t_gere	gl_delimitor[] =
{
  {";", gere_dotcoma, 1},
  {"||", gere_or, 2},
  {"&&", gere_and, 2},
  {0, 0, 0},
};

int	gere_delimitor(t_info *info, char *str, int flag)
{
  int	igl;
  int	istr;
  int	bracket;

  igl = 0;
  bracket = 0;
  while (gl_delimitor[igl].size_str != 0)
    {
      istr = 0;
      while (str[istr] != '\0')
	{
	  if (str[istr] == '(')
	    bracket++;
	  if (bracket == 0 || gl_delimitor[igl].str[0] == '(')
	    if (my_strncmp(&str[istr], gl_delimitor[igl].str, gl_delimitor[igl].size_str) == 0)
	      return (gl_delimitor[igl].func(info, str, flag));
	  if (str[istr] == ')')
	    bracket--;
	  istr++;
	}
      igl++;
    }
  return (NO_REDIRECTION);
}
