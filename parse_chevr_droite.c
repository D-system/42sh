/*
** parse_chevr_droite.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/gp2/work
**
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
**
** Started on  Sun Jun  1 04:34:13 2008 nicolas mondange
** Last update Sun Jun  1 04:57:51 2008 aymeric derazey
*/

#include "42.h"

int	parse_chevr_d(char *buff)
{
  if (chevr_d_begin(buff) == EXIT_FAILURE)
    if (chevr_d_space_chevr_d(buff) == EXIT_FAILURE)
      if (chevr_d_end(buff) == EXIT_FAILURE)
	return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}

int	chevr_d_space_chevr_d(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    {
      if (buff[i] == '>')
	{
	  i++;
	  if ((check_sec_chevr_d(buff, &i)) == EXIT_SUCCESS)
	    return (EXIT_SUCCESS);
	}
      if (buff[i] != '\0')
	i++;
    }
  return (EXIT_FAILURE);
}

int	check_sec_chevr_d(char *buff, int *i)
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

int	chevr_d_end(char *buff)
{
  int	i;

  i = 0;
  while (buff[i] != '\0')
    i++;
  i-- ;
  if (buff[i] == '|' || buff[i] == '<'
      || buff[i] == '>' || buff[i] == '&')
    {
      my_printf("%E", "Invalid null command.\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}

int	chevr_d_begin(char *buff)
{
  if (buff[0] == '>')
    {
      my_printf("%E", "Missing name for redirect.\n");
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
