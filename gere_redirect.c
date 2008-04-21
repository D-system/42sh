/*
** gere_redirect.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:33:56 2008 laurent lefebvre
** Last update Mon Apr 21 17:44:26 2008 thomas brennetot
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
/*   {"??", command, ??}, */
};

int	gere_redirect()
{
  int	igl;

  igl = 0;
  while (my_strncmp(get_next_line(0), gl_gere[igl].str, gl_gere[igl].size_str) != 0)
    igl++;
  return (EXIT_SUCCESS);
}
