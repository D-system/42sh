/*
** get_cfg.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu May 29 18:55:25 2008 aymeric derazey
** Last update Sun Jun  1 07:00:29 2008 aymeric derazey
*/

/*
** Lit le fichier de configuration 42shrc et set les variables en consequences.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "42.h"

void	get_cfg(t_info *info)
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
      xclose(fd);
    }
}
