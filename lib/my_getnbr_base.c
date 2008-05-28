/*
** my_getnbr_base.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:43:27 2008 thomas brennetot
** Last update Tue May 27 19:24:36 2008 aymeric derazey
*/

#include "42.h"

int	find_pos(char c, char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	return (i);
      i++;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char* base)
{
  int	result;
  int	len_base;
  int	len_str;
  int	fact;

  if (str[0] == '-')
      return(-my_getnbr_base(str + 1, base));
  fact = 1;
  len_base = my_strlen(base);
  len_str = my_strlen(str) - 1;
  result = 0;
  while (len_str >= 0)
    {
      result = result + find_pos(str[len_str], base) * fact;
      fact = len_base * fact;
      len_str--;
    }
  return (result);
}
