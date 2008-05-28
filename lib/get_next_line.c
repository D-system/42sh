/*
** get_next_line2.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun May 11 15:10:21 2008 thomas brennetot
** Last update Tue May 27 19:24:04 2008 aymeric derazey
*/

#include <stdlib.h>
#include "42.h"

#define READ_SIZE 2048

char		*get_next_line(int fd)
{
  static char	buffer[READ_SIZE];
  static int	pos = 0;
  static int	size = -1;
  int		pos2;
  char		*s2;
  char		*s3;
  char		*s4;

  if (size < 0 || pos >= size)
    {
      if (!(size = xread(fd, buffer, READ_SIZE - 1)))
	return (NULL);
      pos = 0;
    }
  pos2 = pos;
  while (42)
    {
      if (pos2 >= size)
	{
	  s2 = xmalloc(pos2 - pos + 1);
	  my_strncpy(s2, buffer + pos, pos2 - pos);
	  s2[pos2 - pos] = 0;
	  size = -1;
	  if ((s3 = get_next_line(fd)))
	    {
	      s4 = xmalloc(my_strlen(s2) + my_strlen(s3) + 1);
	      my_strncpy(s4, s2, my_strlen(s2));
	      my_strncpy(s4 + my_strlen(s2), s3, my_strlen(s3));
	      s4[my_strlen(s2) + my_strlen(s3)] = 0;
	      xfree(s2);
	      xfree(s3);
	      return (s4);
	    }
	  else
	    return (s2);
	}
      if (*(buffer + pos2) == '\n')
	{
	  s2 = xmalloc(pos2 - pos + 1);
	  my_strncpy(s2, buffer + pos, pos2 - pos);
	  s2[pos2 - pos] = 0;
	  pos = pos2 + 1;
	  return (s2);
	}
      pos2 ++;
    }
}
