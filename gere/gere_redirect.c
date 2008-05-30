/*
** gere_redirect.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 30 11:03:44 2008 thomas brennetot
** Last update Thu May 15 12:45:00 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

/*
** Lance les fonctions qui font les redirections
*/

t_gere	gl_redirect[] =
{
  {"(", gere_bracket, 1},
/*   {"<<", gere_double_left, 2}, */
  {">>", gere_double_right, 2},
  {"<", gere_left, 1},
  {">", gere_right, 1},
  {"|", gere_pipe, 1},
  {0, 0, 0},
};

int	gere_redirect(t_info *info, char *str, int flag)
{
  int	igl;
  int	istr;
  int	bracket;

  istr = 0;
  bracket = 0;
  while (str[istr] != '\0')
    {
      igl = 0;
      while (gl_redirect[igl].size_str != 0)
	{
	  if (str[istr] == '(')
	    bracket++;
	  if (bracket == 0 || gl_redirect[igl].str[0] == '(')
	    if (my_strncmp(&str[istr], gl_redirect[igl].str, gl_redirect[igl].size_str) == 0)
	      return (gl_redirect[igl].func(info, str, flag));
	  if (str[istr] == ')')
	    bracket--;
	  igl++;
	}
      istr++;
    }
  return (NO_REDIRECTION);
}
