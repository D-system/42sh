/*
** get_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  2 23:34:02 2008 aymeric derazey
** Last update Thu May  8 16:33:08 2008 aymeric derazey
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include "42.h"

int	get_set(t_info *info)
{
  int	size;
  char	*user;

  if ((user = getlogin()) == NULL)
    return (EXIT_FAILURE);
  /* size = get_size(); */
  size = 2;
  if ((info->set = xmalloc(sizeof(*(info->set)) * (size + 1))) == NULL)
      return (EXIT_FAILURE);
  info->set[0] = my_strdup(user); /* en dur pour l'instant */
  info->set[1] = NULL;
  return (EXIT_SUCCESS);
}


/*
** Permet de savoir de combien l'on doit malloc le char **set.
*/

/* int	get_size() */
/* { */
/*   int	size; */
/*   char	*login; */
/*   t_pid	grp; */
/*   t_pid	uid; */
  
/*   size = 0; */
/*   if (login = getlogin() != NULL) */
/*     size++; */
/*   grp = getegid(); */
/*   size++; */
/*   uid = getuid(); */
/*   size++; */
/*   return (size); */
/* } */
