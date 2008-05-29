/*
** gere_key.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/doss_42
** 
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
** 
** Started on  Thu May 29 18:39:46 2008 nicolas mondange
** Last update Thu May 29 23:52:29 2008 nicolas mondange
*/

#include "42.h"

int		gere_key_enter(t_info *info, char *buff)
{
  return (0);
}

int		gere_key_up(t_info *info, char *buff)
{
  memset(buff, 0, BUFF_COMPL);
  info->hist_m++;
  give_event(info, buff, info->hist_m);
  return (1);
}

int		gere_key_down(t_info *info, char *buff)
{
  memset(buff, 0, BUFF_COMPL);
  if (info->hist_m > 0)
    info->hist_m--;
  give_event(info, buff, info->hist_m);
  return (1);
}

int		gere_key_right(t_info *info, char *buff)
{
  return (1);
}

int		gere_key_left(t_info *info, char *buff)
{
  return (1);
}

int		gere_key_back(t_info *info, char *buff)
{
  int		i;
  
  i = 0;
  while (buff[i] != '\0')
    ++i;
  --i;
  buff[i] = '\0';
  return (1);
}

int		gere_key_del(t_info *info, char *buff)
{
  int		i;
  
  i = 0;
  while (buff[i] != '\0')
    ++i;
  --i;
  buff[i] = '\0';
  return (1);
}
