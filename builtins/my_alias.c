/*
** alias.c for 42 in /u/epitech_2012/lefebv_l/cu/public/42sh/alias
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Thu May 29 11:31:19 2008 laurent lefebvre
** Last update Thu May 29 18:47:13 2008 laurent lefebvre
*/

#include "42.h"
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

void		display_alias(t_alias *alist);

void		push_alias(t_alias *alist, char *alias, char *cmd)
{
  t_alias	*current;
  t_alias	*new;

  current = alist;
  while (current->next != NULL)
    current = current->next;
  new = xmalloc(sizeof(*new));
  my_memset(new, 0, sizeof(*new));
  new->alias = strdup(alias);
  new->cmd = strdup(cmd);
  new->next = NULL;
  current->next = new;
}

void		put_alias(t_alias *alist, char *alias, char *cmd)
{
  t_alias	*prev;
  t_alias	*current;

  prev = NULL;
  current = alist;
  if (!my_strcmp(alias, "alias") || !my_strcmp(cmd, "alias"))
    {
      printf("alias: Too dangerous to alias that.\n");
      return ;
    }
  while (current != NULL)
    {
      if (current->alias != NULL && !my_strcmp(alias, current->alias))
	{
	  if (prev != NULL)
	    prev->next = current->next;
	  xfree(current->alias);
	  xfree(current->cmd);
	  xfree(current);
	  push_alias(current, alias, cmd);
	  return ;
	}
      prev = current;
      current = current->next;
    }
  push_alias(alist, alias, cmd);
}

int	set_alias(t_info *info, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  if (i == 0 || (i > 0 && (my_strcmp(tab[0], "alias"))))
    {
      free_tab(tab);
      return (EXIT_FAILURE);
    }
  if (i == 1)
    display_alias(info->alias);
  else if (i == 3)
    put_alias(info->alias, tab[1], tab[2]);
  else
    printf("To many or to few arguments to alias\n");
  /*free_tab(tab);*/
  return (EXIT_SUCCESS);
}

void		display_alias(t_alias *alist)
{
  if (alist->next == NULL)
    return ;
  printf("alias list:\n");
  while (alist->next != NULL)
    {
      printf("%s\t<->\t%s\n", alist->next->alias, alist->next->cmd);
      alist = alist->next;
    }
}

/*
int		main()
{
  char		buffer[1024];
  t_alias	alist;

  my_memset(&alist, 0, sizeof(alist));
  alist.next = NULL;
  my_memset(buffer, 0, 1024);
  while (read(0, buffer, 1024 - 1) != 0)
    {
      buffer[strlen(buffer) - 1] = 0;
      set_alias(&alist, buffer);
      my_memset(buffer, 0, 1024);
    }
  return (EXIT_SUCCESS);
}
*/
