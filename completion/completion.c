/*
** completion.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Thu Apr 24 14:52:07 2008 thomas brennetot
** Last update Sun Jun  1 03:13:24 2008 laurent lefebvre
*/

#include <stdlib.h>
#include "42.h"

char	*completion(t_info *info)
{
  static int	i = 0;
  char	buff[BUFF_COMPL];
 
  my_memset(buff, 0, BUFF_COMPL);
  if (xread(0, buff, BUFF_COMPL - 1) == -1)
    return (NULL);
  buff[my_strlen(buff) - 1] = '\0';
  i++;
  if (i > 50)
    {
      debug("%E",
	    "Je crois que tous le monde a compris qu'il y a un prob, non ?\n");
      exit(-1);
    }
  return (my_strdup(buff));
  info = NULL;
}
