/*
** history.c for  in /u/epitech_2012/mondan_n/cu/public/Dossier_Laurent/42sh
** 
** Made by nicolas mondange
** Login   <mondan_n@epitech.net>
** 
** Started on  Wed Apr 30 16:31:47 2008 nicolas mondange
** Last update Fri May  2 20:23:18 2008 thomas brennetot
*/

#include "42.h"
#define MAX_HISTORY 20

void		load_event(t_info *params)
{
  char		*line;
  int		fd;

  if ((fd = xopen(".history", O_CREAT|O_RDONLY)) != -1)
    {
      line = get_next_line(fd);
      while (line != '\0')
	{
	  line = get_next_line(fd);
	  parse_event(params, line);
	}
      xclose(fd);
    }
}

void		my_word_str(char *str, char c)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	str[i] = '\0';
      i++;
    }
}

void		read_line(t_event *new_elem, char *line)
{
  char		*str;

  str = my_strdup(line);
  my_word_str(str, '\t');
  str++;
  new_elem->nbr = my_getnbr(str);
  while (*str != '\0')
    str++;
  str++;
  new_elem->time = my_strdup(str);
  while (*str != '\0')
    str++;
  str++;
  new_elem->info = my_strdup(str);
  xfree(str);
}

void		parse_event(t_info *params, char *line)
{
  t_event		*buff;
  t_event		*new_elem;

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
	      xwrite(fd, "\t", 1);
	      put_nbr_fd(buff->nbr, fd);
	      xwrite(fd, "\t", 1);
	      xwrite(fd, buff->time, my_strlen(buff->time));
	      xwrite(fd, "\t", 1);
	      xwrite(fd, buff->info, my_strlen(buff->info));
	      xwrite(fd, "\t", 1);
	    }
	  xwrite(fd, "\n", 1);
	}
      xclose(fd);
    }
}

void		add_event(t_info *params, char *to_ad)
{
  int			i;
  time_t		*clock;
  t_event		*buff;
  t_event		*new_elem;
  char			*to_add;

  i = 0;
  to_add = my_strdup(to_ad);
  time(clock);
  if (params->history == NULL)
    first_event(params, to_add, clock);
  else
    {
      buff = params->history;
      while (buff->next != NULL)
	{
	  buff = buff->next;
	  i++;
	}
      new_elem = xmalloc(sizeof(*new_elem));
      new_elem->next = NULL;
      new_elem->nbr = params->nbr_cmd;
      new_elem->time = my_strdup(ctime(clock));
      new_elem->info = my_strdup(to_add);
      buff->next = new_elem;
    }
  if (i > MAX_HISTORY)
    clear_event(params, i, MAX_HISTORY);
  free(to_add);
}

t_event         *read_first_line(t_info *params, char *line)
{
  t_event               *new_elem;
  
  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->next = NULL;
  params->history = new_elem;
  read_line(new_elem, line);
  return (new_elem);
}

t_event		*first_event(t_info *params, char *to_add, time_t *clock)
{
  t_event		*new_elem;
  
  new_elem = xmalloc(sizeof(*new_elem));
  new_elem->next = NULL;
  params->history = new_elem;
  new_elem->nbr = params->nbr_cmd;
  new_elem->time = my_strdup(ctime(clock));
  new_elem->info = my_strdup(to_add);
  return (new_elem);
}

void		aff_event(t_info *params, char **tab)
{
  t_event	*buff;
  int		i;
  
  i = 0;  
  buff = params->history;
  while (buff != NULL)
    {
      my_putstr(buff->info);
      my_putchar('\n');
      buff = buff->next;
      i++;
    }
  tab++;
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
      limit++;
    }
  params->history = buff;
}
