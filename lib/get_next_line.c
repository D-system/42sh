/*
** 3.c for  in /u/epitech_2012/brenne_t/cu/rendu/c/get_next_line_test
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Dec 10 15:12:23 2007 thomas brennetot
** Last update Wed Apr 23 16:00:10 2008 thomas brennetot
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "../42.h"

char		*get_next_line(const int fd)
{
  static char	buffer[BUFF_GNL];
  static int	start;
  static int	rd_val;
  t_stat	stat;

  if (rd_val == 0)
    rd_val = xread(fd, buffer, BUFF_GNL);
  stat.str = 0;
  stat.i = start;
  while (rd_val != 0 && buffer[stat.i] != '\n')
    {
      while (stat.i < rd_val && buffer[stat.i] != '\n')
	stat.i++;
      stat.str = my_concat(buffer, stat.str, start, stat.i);
      start = stat.i + 1;
      if (start >= (rd_val - 1))
	{
	  stat.i = 0;
	  start = 0;
	  rd_val = xread(fd, buffer, BUFF_GNL);
	}
    }
  return (stat.str);
}

char		*my_concat(char *buffer, char *str, int start, int i)
{
  char		*temp;
  int		block;
  int		size;

  block = 0;
  if (str != 0)
    {
      size = my_strlen(str);
      temp = xmalloc(sizeof(*temp) * ((i - start) + size + 1));
      while (str[block] != '\0')
	{
	  temp[block] = str[block];
	  block++;
	}
    }
  else
    temp = xmalloc(sizeof(*str) * ((i - start) + 1));
  while (start < i)
    temp[block++] = buffer[start++];
  temp[block] = '\0';
  return (temp);
}
