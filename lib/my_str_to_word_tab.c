/*
** my_str_to_word_tab.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/gp1
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Mon Apr  7 16:19:25 2008 laurent lefebvre
** Last update Wed Apr 16 15:22:51 2008 nicolas mondange
*/

#include "../42.h"
#include <stdio.h>

void	my_inhib(char *str, int *i)
{
  char	inhib[] = "\'\"`";
  int	d;
  int	f;
  
  d = 0;
  f = 0;
  while (inhib[d] != '\0')
    {
      if (inhib[d] == str[(*i)])
	{
	  f = (*i);
	  (*i)++;
	  while (str[(*i)] != '\0' && str[(*i)] != str[f])
	    (*i)++;
	  if (str[(*i)] == '\0')
	    {
	      my_putstr("Unmatched ");
	      my_putchar(str[f]);
	      my_putstr(".\n");
	    }
	  else
	    (*i)++;
	  return ;
	}
      d++;
    }
}

void	my_delim(char *str, char *delim, int *i, int *j)
{
  int	m;
  int	d;
  int	f;
  
  m = 0;
  d = 0;
  while (delim[d] != '\0')
    {
      f = 0;
      while (delim[d] == str[(*i)])
	{
	  str[(*i)] = '\0';
	  if (f == 0)
	    (*j)++;
	  (*i)++;
	  f++;
	  m++;
	}
      d++;
    }
  if (m > 0)
    (*i)--;
}

int	get_word(char *str, char *delim)
{
  int	i;
  int	j;
  
  i = 0;
  j = 0;
  while (str[i])
    {
      my_inhib(str, &i);
      my_delim(str, delim, &i, &j);
      i++;
    }
  return (j + 1);
}
  
char	*strdup_inhib(char *str)
{
  char	*mem;
  int	i;
  int	j;
  
  j = 0;
  if (str[0] != '\'' && str[0] != '\"' && str[0] != '`')
    mem = strdup(str);
  else
    {
      mem = xmalloc(sizeof(char) * (my_strlen(str) - 2 + 1));
      i = 0;
      while (str[i+j])
	{
	  if (str[i+j] != str[0])
	    {
	      mem[i] = str[i+j];
	      i++;
	    }
	  else
	    j++;
	}
      mem[i] = '\0';
    }
  return (mem);
}

char	**my_str_to_word_tab(char *src, char *delim)
{
  int	i;
  int	n;
  char	**tab;
  char	*str;
  
  i = 0;
  str = strdup(src); /***/
  n = get_word(str, delim);
  printf("I have %d arguments\n", n); /***/
  tab = malloc(sizeof(*tab) * (n + 1)); /***/
  while (i < n)
    {
      tab[i] = strdup_inhib(str);
      while (*str != '\0')
	str++;
      while (*str == '\0')
	str++;
      i++;
    }
  tab[i] = '\0';
  return (tab);
}


/*
int	main()
{
  int	i;
  char	**tab;
  char	buffer[2048];
  
  i = 0;
  read(1, buffer, 2048);
  tab = my_str_to_word_tab(buffer, " \t");
  while (tab[i] != 0)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
  return (0);
  }*/
