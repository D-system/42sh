/*
** put_nbr_fd.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/dosstest/lib
** 
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
** 
** Started on  Fri May  2 19:31:17 2008 nicolas mondange
** Last update Fri May  2 19:45:14 2008 nicolas mondange
*/

#include "../42.h"

void	put_nbr_fd(int nb, int fd)
{
  char	a;
  
  if (nb < 0)
    {
      write(fd, "-", 1);
      put_nbr_fd(-nb, fd);
    }
  else
    {
      if (nb < 10)
	{
	  a = (nb + '0');
	  write(fd, &a, 1);
	}
      else
	{
	  put_nbr_fd(nb / 10, fd);
	  a = ((nb % 10) + '0');
	  write(fd, &a, 1);
	}
    }
  return;
}
