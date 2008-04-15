/*
** my_strcat.c for minishell3 in /u/epitech_2012/deraze_a/cu/rendu/c/minishell3/lib
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat Mar 15 16:19:11 2008 aymeric derazey
** Last update Mon Apr  7 19:41:22 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

char	*my_strcat(char *s1, char *s2)
{
  char	*buff;
  int	len1;
  int	len2;
  int	i;
  int	j;

  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  if ((buff = xmalloc(sizeof(buff) * ((len1 + len2) + 1))) == NULL)
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
