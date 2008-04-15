/*
** get_next_line.h for  in /u/epitech_2012/brenne_t/cu/rendu/c/get_next_line
** 
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
** 
** Started on  Mon Dec 10 15:26:47 2007 thomas brennetot
** Last update Tue Apr  8 12:00:38 2008 thomas brennetot
*/

#ifndef _GET_NEXT_LINE_H_
#define _GET_NEXT_LINE_H_

#define BUFF_GNL 512

typedef struct	t_stat
{
  char		*str;
  int		i;
}		t_stat;

char		*get_next_line(const int fd);
char		*my_concat(char *buffer, char *str, int start, int i);

#endif
