/*
** my_strcat_trois.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  9 21:05:48 2008 aymeric derazey
** Last update Sun May 11 14:51:25 2008 thomas brennetot
*/

#include "../42.h"

char	*my_strcat_trois(char *s1, char *s2, char *s3)
{
  
  char  *buff;
  int   i;
  int   j;
  
  if ((buff = xmalloc(sizeof(*buff) * ((my_strlen(s1) +
					my_strlen(s2) + my_strlen(s3)) + 1))) == NULL)
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
  j = 0;
  while (s3[j] != '\0')
    buff[i++] = s3[j++];
  buff[i] = '\0';
  return (buff);
}
