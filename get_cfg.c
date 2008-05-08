/*
** get_cfg.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu Apr 24 19:46:54 2008 aymeric derazey
** Last update Thu May  8 18:06:38 2008 thomas brennetot
*/


/*
** Lit le fichier de configuration 42shrc et set les variables en consequences.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "42.h"

int	get_cfg(t_info *info)
{
  int	fd;

  if ((fd = open("42shrc", O_RDONLY)) == -1)
    return (EXIT_SUCCESS);
  close(fd);
  return (EXIT_SUCCESS);
}
