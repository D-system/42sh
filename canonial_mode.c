/*
** canonial_mode.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Wed Apr 30 18:16:06 2008 aymeric derazey
** Last update Tue May 27 19:57:13 2008 aymeric derazey
*/

#include <sys/termios.h>
#include "42.h"
#define ON 1
#define OFF 0

int	canonical_mode(int flag)
{
  struct termios	t;

  if (flag == OFF)
    {
      if (ioctl(0, TIOCGETA, &t) < 0)
	return (EXIT_FAILURE);
      t.c_lflag &= ~(ICANON|ECHO|ISIG);
      t.c_cc[VMIN] = 1;
      t.c_cc[VTIME] = 0;
      if (ioctl(0, TIOCSETA, &t) < 0)
	return (EXIT_FAILURE);
    }
  if (flag == ON)
    {
      t.c_lflag |= (ICANON|ECHO|ISIG);
      if (ioctl(0, TIOCSETA, &t) < 0)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
