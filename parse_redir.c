/*
** parse_delim.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sun Jun  1 00:47:27 2008 aymeric derazey
** Last update Sun Jun  1 04:47:59 2008 aymeric derazey
*/

#include "42.h"

int	parse_redir(char *str)
{
  char	*save;

  save = my_strdup(str);
  save = epurstr(save);
  if ((parse_pipe(save)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((parse_chevr_g(save)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((parse_chevr_d(save)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
