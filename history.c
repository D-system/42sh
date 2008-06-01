/*
** history.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh
**
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
**
** Started on  Wed Apr 30 16:31:47 2008 nicolas mondange
** Last update Sun Jun  1 03:44:44 2008 laurent lefebvre
*/

#include <fcntl.h>
#include <time.h>
#include "42.h"
#define MAX_HISTORY 100

void		load_event(t_info *params)
{
  char		*line;
  int		fd;
  
  if ((fd = open(".history", O_RDONLY)) != -1)
    {
      while ((line = get_next_line(fd)) != NULL)
	{
	  if (my_cmp(line, '\t') == 2)
	    parse_event(params, line);
	  xfree(line);
	}
      xclose(fd);
    }
}

void		parse_event(t_info *params, char *line)
{
  t_event	*buff;
  t_event	*new_elem;

  if (params->history == NULL)
    read_first_line(params, line);
  else
    {
      buff = params->history;
      while (buff->next != NULL)
	buff = buff->next;
      new_elem = xmalloc(sizeof(*new_elem));
      new_elem->next = NULL;
      read_line(new_elem, line);
      buff->next = new_elem;
      if (params->nbr_cmd < new_elem->nbr)
	params->nbr_cmd = new_elem->nbr + 1;
    }
}

void		save_event(t_info *params)
{
  int		fd;
  t_event	*buff;

  if ((fd = xopen(".history", O_CREAT|O_WRONLY|O_TRUNC)) != -1)
    {
      if (params->history != NULL)
	{
	  buff = params->history;
	  while (buff != NULL)
	    {
	      put_nbr_fd(buff->nbr, fd);
	      xwrite(fd, "\t", 1);
	      xwrite(fd, buff->time, my_strlen(buff->time));
	      xwrite(fd, "\t", 1);
	      xwrite(fd, buff->info, my_strlen(buff->info));
	      xwrite(fd, "\n", 1);
	      buff = buff->next;
	    }
	}
      xclose(fd);
    }
}

t_event		*find_buff(t_info *params, char *to_add, time_t *clock, int *j)
{
  t_event	*buff;
  int		i;
  
  i = 0;
  if (params->history == NULL)
    {
      first_event(params, to_add, clock);
      return (NULL);
    }
  else
    {
      buff = params->history;
      while (buff->next != NULL)
	{
	  buff = buff->next;
	  ++i;
	}
    }
  *j = i;
  return (buff);
}

void		add_event(t_info *params, char *to_ad)
{
  int			i;
  time_t		clock;
  t_event		*buff;
  t_event		*new_elem;
  char			*to_add;

  i = 0;
  params->hist_max = MAX_HISTORY;
  to_add = my_strdup(to_ad);
  time(&clock);
  buff = find_buff(params, to_add, &clock, &i);
  if (buff != NULL)
    {
      new_elem = xmalloc(sizeof(*new_elem));
      new_elem->next = NULL;
      new_elem->nbr = params->nbr_cmd++;
      new_elem->time = my_strdup(ctime(&clock));
      new_elem->time[my_strlen(new_elem->time) - 1] = '\0';
      new_elem->info = my_strdup(to_add);
      buff->next = new_elem;
      if (i > params->hist_max)
	clear_event(params, i, params->hist_max);
      xfree(to_add);
    }
}
