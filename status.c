/*
** last_status.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Sat May  3 12:00:57 2008 aymeric derazey
** Last update Tue May 27 20:21:26 2008 aymeric derazey
*/

#include "42.h"

/*
** indique lorsqu'une fonction se termine, si elle a reussi ou non.
*/

int	status(t_info *info, int status)
{
  info->last_status = status;
  return (status);
}
