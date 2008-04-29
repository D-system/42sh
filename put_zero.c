/*
** put_zero.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Mon Apr 28 15:53:11 2008 aymeric derazey
** Last update Mon Apr 28 16:19:06 2008 aymeric derazey
*/

#include "42.h"

/*
** Insere un '\0' dans une chaine de caracetere en tenant compte des parentheses (priorite).
*/

int	put_zero(char *str, char *delim)
{
  int	i;
  int	bracket;
  int	len;

  len = my_strlen(delim);
  i = 0;
  bracket = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	bracket++;
      if ((my_strncmp(str + i, delim, len) == 0) && (bracket == 0))
	{
	  str[i] = '\0';
	  return (i);
	}
      if (str[i] == ')')
	bracket--;
      i++;
    }
  return (-1);
}
