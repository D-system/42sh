/*
** my_strcat.c for minishell3 in /u/epitech_2012/deraze_a/cu/rendu/c/minishell3/lib
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Sat Mar 15 16:19:11 2008 aymeric derazey
** Last update Tue May 27 19:26:58 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

char	*my_strcat(char *s1, char *s2)
{
  char	*buff;
  int	i;
  int	j;

  if ((buff = xmalloc(sizeof(*buff) * (my_strlen(s1) + my_strlen(s2) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (s1[i] != '\0')
    {
      buff[i] = s1[i];
      i++;
    }
  j = 0;
  while (s2[j] != '\0')
    buff[i++] = s2[j++];
  buff[i] = '\0';
  return (buff);
}
