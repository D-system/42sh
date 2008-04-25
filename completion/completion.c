/*
** completion.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Thu Apr 24 14:52:07 2008 thomas brennetot
** Last update Thu Apr 24 15:03:52 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

int	completion(t_info *info, char *str)
{
  my_memset(str, '\0', BUFF_COMPL);
  xread(0, str, BUFF_COMPL - 1);
  str[my_strlen(str) - 1] = '\0';
  return (EXIT_SUCCESS);
}
