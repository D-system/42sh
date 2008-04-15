/*
** xmalloc_01.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Fri Apr  4 16:53:03 2008 laurent lefebvre
** Last update Fri Apr  4 18:58:27 2008 thomas brennetot
*/

#include "../42.h"
#include <stdlib.h>

/*
** xmalloc evolue: listage des elements malloques, free d'un element ou de tous
*/

void		*xmalloc(int size)
{
  void		*ret;
  t_mal		*list;
  
  ret = malloc(size);
  if (ret == NULL)
    {
      my_putstr("Memory Allocation Error\n");
      return (0);
    }
  list = mem_add(0, 0);
  my_put_in_list(&list, ret);
  mem_add(1, list);
  return (ret);
}


void		*mem_add(int rw, void *to_mem)
{
  static t_mal	*mem = 0;
  
  if (rw)
    mem = to_mem;
  else
    return (mem);
  return (0);
}

void		my_put_in_list(t_mal **begin, void *add)
{
  t_mal		*new_elem;

  new_elem = x_malloc(sizeof(*new_elem));
  new_elem->addr = add;
  new_elem->next = *begin;
  *begin = new_elem;
}

void		*x_malloc(int size)
{
  void		*ret;

  ret = malloc(size);
  if (ret == NULL)
    {
      my_putstr("Memory Allocation Error\n");
      exit(EXIT_FAILURE);
    }
  return (ret);
}
