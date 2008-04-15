/*
** gere_redirect.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue Apr  1 12:33:56 2008 laurent lefebvre
** Last update Tue Apr  1 12:53:51 2008 laurent lefebvre
*/

#include "42.h"

/*
** Fonction de recursivite. Appels:
** - gere_dotcoma si ";"
** - gere_left si "<"
** - gere_pipe si "|"
** - gere_right si ">"
** - command si instruction valide
*/

void	gere_redirect()
{
  my_putstr("--gere_redirect\n");
  gere_dotcoma();
  gere_left();
  gere_pipe();
  gere_right();
  command();
}
