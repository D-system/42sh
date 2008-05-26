/*
** xwrite.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/err
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:55:00 2008 thomas brennetot
** Last update Mon May 26 20:21:35 2008 thomas brennetot
*/

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../42.h"

int		xwrite(int fd, char *str, int size)
{
  int		i;

  i = 0;
  if (fd == 0 || fd == 1 || fd == 2)
    while (i != size)
      {
	if (str[i] > 0.0 && str[i] < 128.0)
	  write(fd, str + i, 1);
	else
	  {
	    my_printf("%E%d", "\\", str[i]);
	    put_nbr_fd(str[i], 2);
	  }
	i++;
      }
  else
    write(fd, str, size);
  return (EXIT_SUCCESS);
}
