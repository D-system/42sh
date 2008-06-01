/*
** cut_delim_nextword_and_return_nextwrod.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Tue Apr 29 17:09:22 2008 thomas brennetot
** Last update Sun Jun  1 03:03:12 2008 laurent lefebvre
*/

#include <stdlib.h>
#include "42.h"

/*
** Trop dur a expliquer ... . Demandez moi, je vous explquerai :p
*/

char		*cdnarn(char *str, char *str_delim, char *delim)
{
  int		i;
  char		**wordtab;
  char		*file;
  int		len;
  
  my_memset(str_delim, 0, BUFF_COMPL);
  i = -1;
  len = my_strlen(delim);
  while (my_strncmp(&str[++i], delim, len) != 0)
    str_delim[i] = str[i];
  str_delim += i;
  i += len;
  if ((wordtab = my_str_to_wordtab(str + i)) == NULL) /* was my_str... */
    return (NULL);
  if ((file = my_strdup(wordtab[0])) == NULL)
    {
      free_tab(wordtab);
      return (NULL);
    }
  len = my_strlen(wordtab[0]);
  while (my_strncmp(&str[i++], wordtab[0], len) != 0);
  i += len;
  my_strcpy(str_delim, &str[i]);
  free_tab(wordtab);
  return (file);
}
