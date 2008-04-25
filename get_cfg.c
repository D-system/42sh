/*
** get_cfg.c for 42sh in /afs/epitech.net/users/epitech_2012/lefebv_l/public/42sh/gp2/work
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Thu Apr 24 19:46:54 2008 aymeric derazey
** Last update Thu Apr 24 20:31:55 2008 aymeric derazey
*/


/*
** Lit le fichier de configuration 42shrc et set les variables en consequences.
*/

#include "42.h"

int	set_default_var(t_info *info)
{
  info.prompt = ">"
    return (0);
}


int	get_cfg(t_info *info)
{
  int	fd;

  if (fd = open("42shrc", O_RDONLY) == 0)
    set_default_var(info);   /* si le fichier de conf n'existe pas on doit seter des valeurs par default */
  return (0);
}
