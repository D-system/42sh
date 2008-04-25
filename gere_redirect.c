/*
** gere_redirect.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:33:56 2008 laurent lefebvre
** Last update Thu Apr 24 15:32:06 2008 thomas brennetot
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
  {"(", gere_bracket, 1},
  {"||", gere_or, 2},
  {"&&", gere_and, 2},
  {";", gere_dotcoma, 1},
  {"<<", gere_double_left, 2},
  {">>", gere_double_right, 2},
  {"<", gere_left, 1},
  {">", gere_right, 1},
  {"|", gere_pipe, 1},
  {0, 0, 0},
};

int	gere_redirect(t_info *info, char *str)
{
  int	igl;
  int	result;

  igl = 0;
  while (my_strncmp(str, gl_gere[igl].str, gl_gere[igl].size_str) != 0 &&  gl_gere[igl].size_str != 0)
    igl++;
  if (my_strncmp(str, gl_gere[igl].str, gl_gere[igl].size_str) == 0)
    gl_gere[igl].func();
  my_printf("3\n");
  if (builtins(info, str) == EXIT_FAILURE)
    {
      my_printf("4\n");
      if (exec(info, str) == EXIT_FAILURE)
	{
	  my_printf("12\n");
	  return (EXIT_FAILURE);
	}
    }
  my_printf("11\n");
  return (EXIT_SUCCESS);
}
