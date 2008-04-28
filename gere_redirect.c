/*
** gere_redirect.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:33:56 2008 laurent lefebvre
** Last update Mon Apr 28 12:19:41 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Fonction de recursivite. Appels:
** - gere_dotcoma si ";"
** - gere_left si "<"
** - gere_pipe si "|"
** - gere_right si ">"
** - command si instruction valide
*/

t_gere	gl_gere[] =
{
  {"||", gere_or, 2},
  {"&&", gere_and, 2},
  {";", gere_dotcoma, 1},
  {"(", gere_bracket, 1},
  {"<<", gere_double_left, 2},
  {">>", gere_double_right, 2},
  {"<", gere_left, 1},
  {">", gere_right, 1},
  {"|", gere_pipe, 1},
  {0, 0, 0},
};

int	gere_redirect_next(t_info *info, char *str, int flag)
{
  int	igl;
  int	istr;
  int	bracket;

  igl = 0;
  bracket = 0;
  while (gl_gere[igl].size_str != 0)
    {
      istr = 0;
      while (str[istr] != '\0')
	{
	  if (str[istr] == '(')
	    bracket++;
	  if (bracket == 0 || gl_gere[igl].str[0] == '(')
	    if (my_strncmp(&str[istr], gl_gere[igl].str, gl_gere[igl].size_str) == 0)
	      return (gl_gere[igl].func(info, str, flag));
	  if (str[istr] == ')')
	    bracket--;
	  istr++;
	}
      igl++;
    }
  return (NO_REDIRECTION);
}

int	gere_redirect(t_info *info, char *str, int flag)
{
  int	value;

  value = gere_redirect_next(info, str, flag);
  if (value == EXIT_SUCCESS || value == EXIT_FAILURE)
    return (EXIT_SUCCESS);
  debug("%E %E%E", "***** La ligne apres decoupage ******", str, "\n");
  if ((value = builtins(info, str)) == EXIT_FAILURE)
    exec(info, str, flag);
  if (value == EXIT_EXIT)
    return (EXIT_EXIT);
  return (EXIT_SUCCESS);
}
