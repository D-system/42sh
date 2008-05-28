/*
** get_set.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Fri May  2 23:34:02 2008 aymeric derazey
** Last update Tue May 27 21:48:45 2008 aymeric derazey
*/

#include <sys/types.h>
#include <stdlib.h>
#include <grp.h>
#include <unistd.h>
#include "42.h"

int	get_local(t_info *info)
{
  int	size;

  size = get_size();
  if ((info->set = xmalloc(sizeof(*(info->set)) * (size + 1))) == NULL)
    return (EXIT_FAILURE);
  if ((get_user(info)) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  get_uid(info);
  get_gid(info);
  get_history(info);
  if ((get_group(info)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

/*
** Permet de savoir de combien l'on doit malloc le char **set.
*/

int	get_size()
{
  int	size;
  char	*login;
  struct group *grp;

  size = 0;
  if ((login = getlogin()) != NULL)
    size++;
  getegid();
  size++;
  getuid();
  size++;
  /* history */
  size++;
  if ((grp = getgrgid(getegid())) != NULL)
    size++;
  return (size);
}

