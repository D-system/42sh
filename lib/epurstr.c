/*
** epurstr.c for minishell3 in /u/epitech_2012/deraze_a/cu/rendu/c/minishell3
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu Mar 20 18:44:17 2008 aymeric derazey
** Last update Fri May  2 19:40:53 2008 thomas brennetot
*/

#include "../42.h"

char		*decal_word(char *buff, int nb_decal, int pos);

void	notabu(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
}

char		*decal_word(char *buff, int nb_decal, int pos)
{
  while (buff[pos + nb_decal] != '\0')
    {
      buff[pos] = buff[pos + nb_decal];
      pos++;
    }
  buff[pos] = '\0';
  return (buff);
}

char		*epurstr(char *str)
{
  int	i;

  notabu(str);
  i = 0;
  while (str[i] == ' ')
    i++;
  decal_word(str, i, 0);
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
        {
	  i++;
          while (str[i] == ' ')
	    decal_word(str, 1, i);
	}
      i++;
    }
  i -= 2;
  while (str[i] == ' ')
    str[i--] = '\0';
  return (str);
}
