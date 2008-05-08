/*
** my_pwd.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Thu May  8 15:21:07 2008 thomas brennetot
** Last update Thu May  8 16:12:54 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

char	*my_pwd(void)
{
  char	*wd;
  char	*cp;

  if ((wd = getwd(NULL)) == NULL)
    my_printf("%E", "Problem for know pwd\n");
  cp = my_strdup(wd);
  free(wd);
  return (cp);
}
