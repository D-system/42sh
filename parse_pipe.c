/*
** parse_pipe.c<2> for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sun Jun  1 00:48:52 2008 aymeric derazey
** Last update Sun Jun  1 04:54:47 2008 aymeric derazey
*/

#include "42.h"

int	parse_pipe(char *buff)
{
  if (pipe_begin(buff) == EXIT_FAILURE)
    if (pipe_space_pipe(buff) == EXIT_FAILURE)
      if (pipe_end(buff) == EXIT_FAILURE)
	return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int	pipe_space_pipe(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '|')
	{
	  i++;
	  if ((check_sec_pipe(buff, &i)) == EXIT_SUCCESS)
	    return (EXIT_SUCCESS);
	}
      if (buff[i] != '\0')
	i++;
    }
  return (EXIT_FAILURE);
}

int	check_sec_pipe(char *buff, int *i)
{
  while (buff[(*i)] != '\0')
    {
      if (buff[(*i)] == '|' || buff[(*i)] == '<'
	  || buff[(*i)] == '>' || buff[(*i)] == '&')
	{
	  my_printf("%E", "Invalid null command.\n");
	  return (EXIT_SUCCESS);
	}
      (*i)++;
    }
  return (EXIT_FAILURE);
}

int	pipe_end(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    i++;
  i-- ;
  if (buff[i] == '|')
    {
      my_printf("%E", "Invalid null command.\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	pipe_begin(char *buff)
{
  if (buff[0] == '|')
    {
      my_printf("%E", "Invalid null command.\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
