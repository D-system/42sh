/*
** my_getnbr.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:42:14 2008 thomas brennetot
** Last update Mon Mar 31 17:20:52 2008 thomas brennetot
*/

#include "../42.h"

int	get_int(char *str, int signe)
{
  int	ret;
  char	c;
  int	bp_neg;

  ret = 0;
  c = *str;
  bp_neg = -2147483647;
  while (c >= '0' && c <= '9')
    {
      ret *= 10;
      ret -= (c - '0');
      if (ret > 0)
        return (0);
      c = *(++str);
    }
  if (signe > 0)
    return ((ret >= bp_neg) ? (-1 * ret) : (0));
  return (ret);
}

int	my_getnbr(char *str)
{
  int	s;
  char	c;

  s = 1;
  c = *str;
  while (c == '+' || c == '-')
    {
      s *= ((c == '-') ? (-1) : (1));
      c = *(++str);
    }
  if (c >= '0' || c <= '9')
    return (get_int(str, s));
  return (0);
}
