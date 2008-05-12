/*
** my_pwd.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Thu May  8 15:21:07 2008 thomas brennetot
** Last update Sun May 11 15:48:30 2008 thomas brennetot
*/

#include <stdlib.h>
#include <unistd.h>
#include "../42.h"

char	*my_pwd(void)
{
  char	*wd;
  char	*cp;

  #if Linux
  if ((wd = getwd(".")) == NULL)
    {
      my_printf("%E", "Problem for know pwd\n");
      return (NULL);
    }
  #endif
  #if FreeBSD
  if ((wd = getwd(NULL)) == NULL)
    {
      my_printf("%E", "Problem for know pwd\n");
      return (NULL);
    }
  #endif
  cp = my_strdup(wd);
  free(wd);
  return (cp);
}
