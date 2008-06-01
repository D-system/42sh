/*
** parse_chevr_gauche.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sun Jun  1 04:23:56 2008 aymeric derazey
** Last update Sun Jun  1 04:57:26 2008 aymeric derazey
*/

#include "42.h"

int	parse_chevr_g(char *buff)
{
  if (chevr_g_begin(buff) == EXIT_FAILURE)
    if (chevr_g_space_chevr_g(buff) == EXIT_FAILURE)
      if (chevr_g_end(buff) == EXIT_FAILURE)
	return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int	chevr_g_space_chevr_g(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '<')
	{
	  i++;
	  if ((check_sec_chevr_g(buff, &i)) == EXIT_SUCCESS)
	    return (EXIT_SUCCESS);
	}
      if (buff[i] != '\0')
	i++;
    }
  return (EXIT_FAILURE);
}

int	check_sec_chevr_g(char *buff, int *i)
{
  while (buff[(*i)] != '\0')
    {
      if (buff[(*i)] == '|' || buff[(*i)] == '<'
	  || buff[(*i)] == '>' || buff[(*i)] == '&')
	{
	  my_printf("%E", "Missing name for redirect.\n");
	  return (EXIT_SUCCESS);
	}
      (*i)++;
    }
  return (EXIT_FAILURE);
}

int	chevr_g_end(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    i++;
  i-- ;
  if (buff[i] == '|' || buff[i] == '<'
      || buff[i] == '>' || buff[i] == '&')
    {
      my_printf("%E", "Missing name for redirect.\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	chevr_g_begin(char *buff)
{
  if (buff[0] == '<')
    {
      my_printf("%E", "Missing name for redirect.\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
