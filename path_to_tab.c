/*
** path_to_tab.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Wed Apr 23 18:10:11 2008 thomas brennetot
** Last update Wed Apr 23 18:21:11 2008 thomas brennetot
*/

#include <stdio.h>
#include "42.h"
#define BUFF_PATH 256

int	how_many_path(char *str)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '=' || str[i] == ':')
	nb++;
      i++;
    }
  return (nb);
}

void	path_to_tab_cut_cp(char buff[BUFF_PATH], char **tab, char *str)
{
  int	ibuff;
  int	istr;
  int	itab;

  istr = 0;
  itab = 0;
  while (str[istr] != '=')
    istr++;
  while (str[istr - 1] != '\0')
    {
      ibuff = 0;
      my_memset(buff, 0, BUFF_PATH);
      while (str[istr] != ':' && str[istr] != '\0')
	buff[ibuff++] = str[istr++];
      tab[itab] = my_strdup(buff);
      itab++;
      istr++;
    }
    tab[itab] = NULL;
}

char	**path_to_tab(char *str)
{
  char	**tab;
  char	buff[BUFF_PATH];

  if (str == NULL)
    {
      if ((tab = xmalloc(sizeof(*tab))) == NULL)
	return (NULL);
      tab[0] = NULL;
      return (tab);
    }
  if ((tab = xmalloc(sizeof(*tab) * (how_many_path(str) + 1))) == NULL)
    return (NULL);
  path_to_tab_cut_cp(buff, tab, str);
  return (tab);
}
