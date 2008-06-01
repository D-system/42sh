/*
** gere_term.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/lefebv_l
** 
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
** 
** Started on  Sun Jun  1 06:48:16 2008 nicolas mondange
** Last update Sun Jun  1 06:58:57 2008 aymeric derazey
*/

#include "42.h"
#include <termcap.h>
#if linux
#include <term.h>
#include <stropts.h>
#endif
#define	BUFF_CHAR	8

void			my_canonical(int i)
{
  static struct termios	t;

  if (i == 1)
    {
#if linux
      if (ioctl(0, TCGETA, &t) < 0)
	my_putstr("TCGETA");
#else
      if (ioctl(0, TIOCGETA, &t) < 0)
	my_putstr("TIOCGETA");
#endif
      t.c_lflag &= ~(ICANON|ECHO|ISIG);
      t.c_cc[VMIN] = 1;
      t.c_cc[VTIME] = 0;
#if linux
      if (ioctl(0, TCSETA, &t) < 0)
	my_putstr("TCSETA");
#else
      if (ioctl(0, TIOCSETA, &t) < 0)
	my_putstr("TIOCSETA");
#endif
    }
  if (i == 0)
    {
      t.c_lflag |= (ICANON|ECHO|ISIG);
#if linux
      if (ioctl(0, TCSETA, &t) < 0)
	my_putstr("TCSETA");
#else
      if (ioctl(0, TIOCSETA, &t) < 0)
	my_putstr("TIOCSETA");
#endif
    }
  return;
}

int		my_compare(char *new)
{
  int	i;

  if (my_strlen(new) == 1 && new[0] == 10)
    i = KEY_ENTER;
  else if (my_strlen(new) == 3 && new[0] == 27 && new[1] == 91 && new[2] == 65)
    i = KEY_UP;
  else if (my_strlen(new) == 3 && new[0] == 27 && new[1] == 91 && new[2] == 66)
    i = KEY_DOWN;
  else if (my_strlen(new) == 3 && new[0] == 27 && new[1] == 91 && new[2] == 67)
    i = KEY_RIGHT;
  else if (my_strlen(new) == 3 && new[0] == 27 && new[1] == 91 && new[2] == 68)
    i = KEY_LEFT;
  else if (my_strlen(new) == 1 && new[0] == 8)
    i = KEY_BACK;
  else if (my_strlen(new) == 4 && new[0] == 27 && new[1] == 91 && new[2] == 51 && new[3] == 126)
    i = KEY_DEL;
  else if (my_strlen(new) == 1 && new[0] == 4)
    i = 42;
  else if (my_strlen(new) == 1 && new[0] == 12)
    i = 40;
  else
    i = -1;
  return (i);
}

int		my_out_c(int c)
{
  my_putchar(c);
  return (0);
}

char		*xtgetstr(char *cap, char **area)
{
  char	*capstr;

  if ((capstr = tgetstr(cap, area)) == NULL)
    {
      my_putstr("problem getting ");
      my_putstr(cap);
      my_putchar('\n');
      exit(1);
    }
  return (capstr);
}

void		my_put_cursor(char *data)
{
  char		*term;
  char		bp[1024];
  char		t[4096];
  char		*area;

  if ((term = getenv("TERM")) == NULL)
    {
      my_putstr("Cannot get terminal");
      exit(1);
    }
  if (tgetent(bp, term) != 1)
    {
      my_putstr("Cant get terminal");
      exit(1);
    }
  area = t;
  tputs(xtgetstr(data, &area), 1 , my_out_c);
}
