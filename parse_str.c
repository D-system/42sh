/*
** parse_str.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Thu Apr 24 13:45:22 2008 thomas brennetot
** Last update Fri May 30 19:44:39 2008 laurent lefebvre
*/

#include <stdlib.h>
#include "42.h"

/*
** Parse la str avant de l'envoyer a gere_redirect
*/

int	parser_nb_bracket(char *str)
{
  int	open1;
  int	close1;
  int	i;
  
  open1 = 0;
  close1 = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '(' && str[i] != ')');
      else if (str[i] == '(')
	open1++;
      else if (str[i] == ')')
	if (++close1 > open1)
	  {
	    my_printf("Too many )'s.\n");
	    return (EXIT_FAILURE);
	  }
      i++;
    }
  if (open1 != close1)
    {
      my_printf("%E", "Too many ('s\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	bracket_valid_before(char *str, int i)
{
  i--;
  while (str[i] == ' ' || str[i] == '\t')
    {
      i--;
      if (i < 0)
	return (EXIT_SUCCESS);
    }
  if (str[i] == '|' || str[i] == '&' || str[i] == '>'
      || str[i] == '<' || str[i] == ';' || '(')
    return (EXIT_SUCCESS);
  my_printf("%E", "Badly placed ()'s.\n");
  return (EXIT_FAILURE);
}

int	bracket_valid_after(char *str, int i)
{
  i++;
  while (str[i] != '\0' && str[i] == ' ' && str[i] == '\t')
    i++;
  if (str[i] == '|' || str[i] == '&' || str[i] == '>' || str[i] == '<'
      || str[i] == '\0' || str[i] == ';' || str[i] == ')')
    {
      my_printf("%E", "Invalid null command.\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

int	parser_bracket_valid(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	{
	  if ((bracket_valid_before(str, i) == EXIT_FAILURE) ||
	      (bracket_valid_after(str, i) == EXIT_FAILURE))
	    return (EXIT_FAILURE);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}

int	parse_str(t_info *info, char *str)
{
  if ((parser_nb_bracket(str) == EXIT_FAILURE) ||
      (parser_bracket_valid(str) == EXIT_FAILURE))
    return (status(info, EXIT_FAILURE));
  if (parse_redirect(info, str) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  info->last_status = 0;
  if (info->nbr_cmd == 0xFFFFFFF)
    info->nbr_cmd = 0;
  return (EXIT_SUCCESS);
}
