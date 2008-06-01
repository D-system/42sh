/*
** history_list.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh/doss_42
** 
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
** 
** Started on  Sun Jun  1 00:14:34 2008 nicolas mondange
** Last update Sun Jun  1 00:16:37 2008 nicolas mondange
*/

#include <fcntl.h>
#include <time.h>
#include "42.h"
#define MAX_HISTORY 100

t_event		*read_first_line(t_info *params, char *line)
{
  t_event	*new_elem;
  
  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->next = NULL;
  params->history = new_elem;
  read_line(new_elem, line);
  return (new_elem);
}

t_event		*first_event(t_info *params, char *to_add, time_t *clock)
{
  t_event	*new_elem;

  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->next = NULL;
  params->history = new_elem;
  new_elem->nbr = params->nbr_cmd++;
  new_elem->time = my_strdup(ctime(clock));
  new_elem->time[my_strlen(new_elem->time) - 1] = '\0';
  new_elem->info = my_strdup(to_add);
  return (new_elem);
}

int		aff_event(t_info *params, char **burne)
{
  t_event	*buff;
  
  buff = params->history;
  while (buff != NULL)
    {
      my_put_nbr(buff->nbr);
      my_putchar('\t');
      my_putstr(buff->time);
      my_putchar('\t');
      my_putstr(buff->info);
      my_putchar('\n');
      buff = buff->next;
    }
  burne++;
  return (EXIT_SUCCESS);
}

void		clear_event(t_info *params, int nbr_elm, int limit)
{
  t_event	*save;
  t_event	*buff;
  
  buff = params->history;
  while ((nbr_elm - limit) > 0 && buff != NULL)
    {
      save = buff;
      buff = buff->next;
      xfree(save->info);
      xfree(save->time);
      xfree(save);
      ++limit;
    }
  params->history = buff;
}

void		give_event(t_info *params, char *to_fill, int limit)
{
  t_event	*buff;
  int		i;
  int		j;
  
  i = 0;
  j = 0;
  buff = params->history;
  while (buff->next != NULL)
    {
      i++;
      buff = buff->next;
    }
  buff = params->history;
  while (buff->next != NULL && j <= i - limit)
    {
      j++;
      buff = buff->next;
    }
  i = 0;
  while (buff->info[i] != '\0')
    {
      to_fill[i] = buff->info[i];
      i++;
    }
}
