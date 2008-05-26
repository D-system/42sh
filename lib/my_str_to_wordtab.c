/*
** my_str_to_wordtab.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work/lib
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Apr 21 17:24:58 2008 thomas brennetot
** Last update Thu May 15 12:11:58 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"
#define BUFF_WORDTAB 256

int	my_str_to_wordtab_nb_word(char *str)
{
  int	i;
  int	space;

  i = 0;
  space = 1;
  if (str[0] != '\0' && str[0] != ' ')
    space++;
  while (str[i] != '\0')
    {
      if (str[i] == ' ')
	{
	  if (str[i + 1] != ' ' && str[i + 1] != '\0')
	    space++;
	}
      i++;
    }
  return (space);
}

void	no_tabulation(char *str)
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

void	no_space_in_end(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  i--;
  while (str[i] == ' ' && i > 0)
    {
      str[i] = '\0';
      i--;
    }
}

char	**my_str_to_wordtab(char *str)
{
  char	**tab;
  char	buff[BUFF_WORDTAB];
  int	i;
  int	u;
  int	itab;

  i = 0;
  itab = 0;
  no_tabulation(str);
  no_space_in_end(str);
  if ((tab = xmalloc(sizeof(*tab) * my_str_to_wordtab_nb_word(str))) == NULL)
    return (NULL);
  if (my_str_to_wordtab_nb_word(str) > 1)
    while (str[i] != '\0')
      {
	u = 0;
	my_memset(buff, 0, BUFF_WORDTAB);
	u = 0;
	while (str[i] == ' ' && str[i] != '\0')
	  i++;
	while (str[i] != ' ' && str[i] != '\0')
	  buff[u++] = str[i++];
	if ((tab[itab] = xmalloc(sizeof(**tab) * (my_strlen(buff) + 1))) == NULL)
	  {
	    free_tab(tab);
	    return (NULL);
	  }
	my_strcpy(tab[itab++], buff);
      }
  tab[itab] = NULL;
  return (tab);
}
