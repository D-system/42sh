/*
** xfree.c for  in /u/epitech_2012/brenne_t/cu/42sh
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Fri Apr  4 18:50:31 2008 thomas brennetot
** Last update Wed Apr 30 13:13:52 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"

void		xfree(void *add)
{
  t_mal		*list;
  t_mal		*prev;
  t_mal		*next;
  int		ch;
  
  if (add == NULL)
    return ;
  ch = 0;
  list = mem_add(0, 0);
  prev = 0;
  while (list->addr != add)
    {
      prev = list;
      list = list->next;
      ch++;
    }
  next = list->next;
  free(add);
  free(list);
  if (prev)
    prev->next = next;
  if (ch == 0)
    mem_add(1, next);
}

void		freeall()
{
  t_mal		*list;
  t_mal		*next;

  list = mem_add(0, 0);
  while (list != NULL)
    {
      next = list->next;
      free(list->addr);
      free(list);
      list = next;
    }
  mem_add(1, 0);
}
