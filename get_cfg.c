/*
** get_cfg.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu Apr 24 19:46:54 2008 aymeric derazey
** Last update Thu May 29 11:06:50 2008 laurent lefebvre
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
  char	*buff;

  if ((fd = open(".42shrc", O_RDONLY)) != -1)
    {
      while ((buff = get_next_line(fd)) != NULL)
	{
	  if (buff[0] != '#')
	    gere(info, buff, FATHER);
	  xfree(buff);
	}
      close(fd);
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
