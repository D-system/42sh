/*
** my_term.h for 42 in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/include
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Tue May 27 19:55:35 2008 aymeric derazey
** Last update Tue May 27 19:56:25 2008 aymeric derazey
*/

#ifndef __MY_TERM__
# define __MY_TERM__

#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/termios.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define BUF_SIZE 4096

typedef	struct		s_list
{
  char			*data;
  struct s_list		*next;
}			t_list;

t_list		*push(t_list *list, char *str);
void		show_list(t_list *list, int pos);

int		canonical_mode(int flag);
void		display(int ac, char **av);
void		reverse_video(t_list *list);
void		clear_win();
void		my_outc(int c);
int		inf_list(int pos, int ac);
int		get_keys1(char *buf, int r, int ac);

#endif /* __MY_TERM_H__ */
