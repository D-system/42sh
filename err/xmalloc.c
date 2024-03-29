/*
** xmalloc_01.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
**
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
**
** Started on  Fri Apr  4 16:53:03 2008 laurent lefebvre
<<<<<<< .mine
<<<<<<< .mine
** Last update Mon May 26 20:21:42 2008 nicolas mondange
=======
** Last update Mon May 26 20:20:36 2008 thomas brennetot
=======
** Last update Tue May 27 19:33:02 2008 aymeric derazey
>>>>>>> .r49
>>>>>>> .r43
*/

#include "42.h"
#include <stdlib.h>

/*
** xmalloc evolue: listage des elements malloques, free d'un element ou de tous
*/

void		*xmalloc(int size)
{
  char		*ret;
  t_mal		*list;

  ret = malloc(size);
  if (ret == NULL)
    {
      my_printf("%E", "Memory Allocation Error\n");
      return (NULL);
    }
  my_memset(ret, 0, sizeof(*ret));
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
      my_printf("%E", "Memory Allocation Error\n");
      return (NULL);
    }
  return (ret);
}
