/*
** my_strlen.c for  in /u/epitech_2012/lefebv_l/public/42sh/official/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Mar 31 16:47:58 2008 thomas brennetot
** Last update Thu May 29 11:21:26 2008 laurent lefebvre
*/

#include "42.h"

int     my_strlen(char *str)
{
  int	result;

  result = 0;
  if (str == NULL)
    {
      my_printf("my_strlen failed: NULL str\n");
      return (-1);
    }
  while (str[result] != '\0')
    result++;
  return (result);
}
