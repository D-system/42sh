/*
** history_lib.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/doss_42
** 
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
** 
** Started on  Sun Jun  1 00:13:29 2008 nicolas mondange
** Last update Sun Jun  1 03:41:39 2008 laurent lefebvre
*/

#include <fcntl.h>
#include <time.h>
#include "42.h"
#define MAX_HISTORY 100

int		my_cmp(char *line, char c)
{
  int		i;
  int		cmp;
  
  i = 0;
  cmp = 0;
  while (line[i] != '\0')
    {
      if (line[i] == c)
	cmp++;
      i++;
    }
  return (cmp);
}

void		my_word_str(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	str[i] = '\0';
      ++i;
    }
}

void		read_line(t_event *new_elem, char *line)
{
  my_word_str(line, '\t');
  new_elem->nbr = my_getnbr(line);
  while (*line != '\0')
    ++line;
  ++line;
  new_elem->time = my_strdup(line);
  while (*line != '\0')
    ++line;
  ++line;
  new_elem->info = my_strdup(line);
}

