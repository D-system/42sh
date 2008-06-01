/*
** alias.c for 42 in /u/epitech_2012/lefebv_l/cu/public/42sh/alias
**
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
**
** Started on  Thu May 29 11:31:19 2008 laurent lefebvre
** Last update Sun Jun  1 06:50:04 2008 thomas brennetot
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

  prev = alist;
  current = alist;
  while (current != NULL)
    {
      if (current->alias != NULL && !my_strcmp(alias, current->alias) &&
	  my_strlen(alias) == my_strlen(current->alias))
	{
	  if (prev != NULL)
	    prev->next = current->next;
	  xfree(current->alias);
	  xfree(current->cmd);
	  xfree(current);
	  push_alias(alist, alias, cmd);
	  return ;
	}
      prev = current;
      current = current->next;
    }
  push_alias(alist, alias, cmd);
}

int	alias_loop(t_alias *alist, char *alias, char *cmd)
{
  t_alias	*current;

  current = alist;
  if ((!my_strcmp(alias, "alias") && my_strlen(alias) == 5) ||
      (!my_strcmp(cmd, "alias") && my_strlen(cmd) == 5) ||
      (!my_strcmp(alias, cmd) && my_strlen(cmd) == my_strlen(alias)))
    {
      my_printf("%E", "alias: Too dangerous to alias that.\n");
      return (EXIT_FAILURE);
    }
  while (current != NULL)
    {
      if (!my_strcmp(current->alias, cmd) &&
	  my_strlen(current->alias) == my_strlen(cmd))
	{
	  my_printf("%E", "'%s' is already used for the aliased string '%s'\n",
		    cmd, current->alias);
	  return (EXIT_FAILURE);
	}
      current = current->next;
    }
  return (EXIT_SUCCESS);
}

int	set_alias(t_info *info, char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    ++i;
  if (i >= 0 && my_strcmp(tab[0], "alias") && my_strlen(tab[0]) == 5)
    {
      free_tab(tab);
      return (EXIT_FAILURE);
    }
  if (i == 1)
    display_alias(info->alias);
  else if (i == 3 && alias_loop(info->alias, tab[1], tab[2]) == EXIT_SUCCESS)
    put_alias(info->alias, tab[1], tab[2]);
  else if (i == 2 || i > 3)
    my_printf("%E", "To many or to few arguments to alias\n");
  return (EXIT_SUCCESS);
}

void		display_alias(t_alias *alist)
{
  if (alist->next == NULL)
    return ;
  my_printf("alias list:\n");
  while (alist->next != NULL)
    {
      my_printf("%s\t<->\t%s\n", alist->next->alias, alist->next->cmd);
      alist = alist->next;
    }
}

int		my_alias(t_info *info, char **tab, char *str)
{
  t_alias	*current;

  current = info->alias;
  if (tab[0] == NULL)
    return (NO_BUILTINS);
  while (current != NULL)
    {
      if (!my_strcmp(tab[0], current->alias) &&
	  my_strlen(tab[0]) == my_strlen(current->alias))
	{
	  gere(info, current->cmd, FATHER);
	  return (EXIT_FAILURE);
	}
      current = current->next;
    }
  return (NO_BUILTINS);
  str = NULL;
}
