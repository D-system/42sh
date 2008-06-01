/*
** my_str_to_word_tab.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/gp1
**
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
**
** Started on  Mon Apr  7 16:19:25 2008 laurent lefebvre
** Last update Sun Jun  1 02:59:21 2008 laurent lefebvre
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define xmalloc malloc
#define my_strlen strlen
#define my_printf printf
#define my_strdup strdup

int	my_inhib(char *str, int *i)
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
	  if (str[(*i)] > 0)
	    (*i)++;
	  while (str[(*i)] > 0 && str[(*i)] != str[f])
	    (*i)++;
	  if (str[(*i)] <= 0)
	    {
	      my_printf("Unmatched %c.\n", str[f]);
	      return (EXIT_FAILURE);
	    }
	  else if (str[(*i)] > 0)
	    (*i)++;
	  return (EXIT_SUCCESS);
	}
      d++;
    }
  return (EXIT_SUCCESS);
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
	  str[(*i)] = 0;
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

  while (str[i] > 0)
    {
      if (my_inhib(str, &i) == EXIT_FAILURE)
	return (-1);
      my_delim(str, delim, &i, &j);
      if (str[i] != -1)
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
  if (str[0] <= 0)
    return (NULL);
  if (str[0] != '\'' && str[0] != '\"' && str[0] != '`')
    mem = my_strdup(str);
  else
    {
      mem = xmalloc(sizeof(*mem) * (my_strlen(str) - 2 + 2));
      i = 0;
      while (str[i + j])
	if (str[i + j] != str[0])
	  {
	    mem[i] = str[i + j];
	    i++;
	  }
	else
	  j++;
      mem[i] = '\0';
    }
  return (mem);
}

int	my_strlen_mode(char *str)
{
  int	i;

  i = 0;
  if (str[0] == 0)
    return (-1);
  while (str[i] > 0)
    i++;
  if (str[i] == -1)
    str[i] = 0;
  return (i);
}

typedef	struct	s_vagin
{
  int		i;
  int		n;
  char		**tab;
  char		*str;
  char		*save;  
}		t_vagin;

char		**str_to_wordtab(char *src, char *delim)
{
  t_vagin	vagin;
  
  vagin.i = 0;
  if ((vagin.str = my_strdup(src)) == NULL)
    return (NULL);
  vagin.save = vagin.str;
  vagin.str[strlen(vagin.str)] = -1;
  if ((vagin.n = get_word(vagin.str, delim)) == -1)
    {
      free(vagin.save);
      return (NULL);
    }
  if ((vagin.tab = xmalloc(sizeof(*vagin.tab) * (vagin.n + 1 + 1))) == NULL)
    return (NULL);
  while (vagin.i < vagin.n)
    {
      if (my_strlen_mode(vagin.str) > 0 &&
	  (vagin.tab[vagin.i] = strdup_inhib(vagin.str)) == NULL)
	return (NULL);
      while (*vagin.str > 0)
	vagin.str++;
      while (vagin.i < vagin.n - 1 && *vagin.str == '\0')
	vagin.str++;
      vagin.i++;
    }
  vagin.tab[vagin.i] = NULL;
  free(vagin.save);
  return (vagin.tab);
}

/*
int	main(int ac, char **av)
{
  int	i = 0;
  char	**tab;
  char	buffer[2048];

  while (42)
    {
      i = 0;
      if (read(0, buffer, 2047) == 0)
	return (0);
      buffer[strlen(buffer) - 1] = 0;
      if ((tab = my_str_to_wordtab_mode(buffer, " \t")) == NULL)
	{
	  my_printf(">>>>>>>>>EXIT_FAILURE<<<<<<<<");
	  return (EXIT_FAILURE);
	}
      memset(buffer, 0, 2048);
      while (tab[i] != NULL)
	{
	  printf("'%s'\n", tab[i]);
	  free(tab[i]);
	  i++;
	}
      free(tab);
    }
  return (0);
}
*/
