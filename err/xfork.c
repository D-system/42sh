/*
** xfork.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Sun Apr 27 13:57:45 2008 thomas brennetot
** Last update Wed Apr 30 11:52:04 2008 thomas brennetot
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "42.h"

int	xfork(void)
{
  int	pid;

  pid = fork();
  if (pid == -1)
    {
      my_printf("%E", "Problem with fork\n");
      return (EXIT_FAILURE);
    }
  return (pid);
}
