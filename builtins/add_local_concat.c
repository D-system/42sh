/*
** add_local_concat.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu May  8 19:29:12 2008 aymeric derazey
** Last update Thu May  8 19:42:02 2008 aymeric derazey
*/

#include "../42.h"

char	*add_local_concat(char *str)
{
  str = replace_char(str, '\t');
  return (str);
}


char	*replace_char(char *str, char c)
{
  int	i;
  
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '=')
	str[i] = c;
      i++;
    }
  return (str);
}
