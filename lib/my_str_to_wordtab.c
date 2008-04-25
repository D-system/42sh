/*
** my_str_to_wordtab.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:24:58 2008 thomas brennetot
** Last update Thu Apr 24 15:57:41 2008 thomas brennetot
*/

#include "../42.h"


char	**my_str_to_wordtab(char *str)
{
  my_printf("17\n");
  return (my_str_to_wordtab_mode(str, " \t"));
}
