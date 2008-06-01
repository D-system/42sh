/*
** gere_keyboard.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/doss_42
**
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
**
** Started on  Wed May 28 19:51:47 2008 nicolas mondange
** Last update Sun Jun  1 06:52:39 2008 nicolas mondange
*/

#include "42.h"
#include <termcap.h>
#if linux
#include <term.h>
#include <stropts.h>
#endif
#define	BUFF_CHAR	8


int		find_key(t_info *info, char *new, char *buff)
{
  int		i;

  if ((i = my_compare(new)) != -1)
    {
      i = do_action(info, i, buff);
      return (i);
    }
  else
    add_to_buff(buff, new);
  return (1);
}

void		my_blank(char *str, t_info *info)
{
  static int	i = 0;
  int	j;

  j = 0;
  if (i == 0)
    {
      i = my_strlen(str);
      return ;
    }
  prompt(info);
  while (j < i)
    {
      my_putchar(' ');
      j++;
    }
  i = my_strlen(str);
  my_putchar('\r');
}

void		add_to_buff(char *buff, char *new)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (buff[i] != '\0' && i < BUFF_COMPL - BUFF_CHAR)
    ++i;
  while (new[j] != '\0')
    buff[i++] = new[j++];
}

struct	s_read
{
  int	i;
  int	(*f)(t_info *params, char *buff);
};

int		do_action(t_info *info, int i, char *buff)
{
  int		j;
  struct s_read	tab[] =
    {
      {KEY_ENTER, gere_key_enter},
      {KEY_UP, gere_key_up},
      {KEY_DOWN, gere_key_down},
      {KEY_RIGHT, gere_key_right},
      {KEY_LEFT, gere_key_left},
      {KEY_DEL, gere_key_del},
      {KEY_BACK, gere_key_back},
      {-1, NULL}
    };
  j = 0;
  while (tab[j].i != i && tab[j].i != -1)
    j++;
  if (tab[j].i != -1)
    i = tab[j].f(info, buff);
  return (i);
}

char		*gere_keyboard(t_info *info)
{
  char	buff[BUFF_COMPL];
  char	new[BUFF_CHAR];
  int	lock;
  int	r;

  lock = 1;
  my_memset(buff, 0, BUFF_COMPL);
  my_canonical(1);
  info->hist_m = 0;
  while (lock == 1)
    {
      my_memset(new, 0, 4);
      r = xread(1, new, 4);
      if (r == -1 || r == 0)
	return (NULL);
      lock = find_key(info, new, buff);
      if (new[0] == 4)
	return (NULL);
      if (new[0] == 12)
	my_put_cursor("cl");
      my_putchar('\r');
      my_blank(buff, info);
      prompt(info);
      my_printf("%s", buff);
    }
  my_putchar('\n');
  my_canonical(0);
  return (my_strdup(buff));
}
