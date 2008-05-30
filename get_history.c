/*
** get_history.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/local
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Tue May 27 20:21:49 2008 aymeric derazey
** Last update Fri May 30 02:19:23 2008 thomas brennetot
*/

#include "42.h"

void	get_history(t_info *info)
{
  int	i;
  char	*fetched;

  if (info->set == NULL)
    return ;
  else if ((fetched = fetch_env(info->set, "history", "\t")) != NULL)
    {
      i = 0;
      while (fetched[i] != '\0')
	{
	  if (fetched[i] == '\t')
	    info->hist_max = atoi(fetched + i + 1);
	  i++;
	}
    }
  else
    {
      info->hist_max = 100;
      i = 0;
      while (info->set[i] != NULL)
	i++;
      info->set[i++] = my_strdup("history\t100");
      info->set[i] = NULL;
    }
}
