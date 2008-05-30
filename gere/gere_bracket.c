/*
** gere_bracket.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Apr 21 17:55:55 2008 thomas brennetot
** Last update Fri May 30 03:31:48 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

void		gere_bracket_copy_between_bracket(char *str, char *buff)
{
  int		i;
  int		u;
  int		start;
  int		bracket;

  i = 0;
  while (str[i++] != '(');
  start = i;
  u = 0;
  bracket = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
        bracket++;
      if (str[i] == ')')
        bracket--;
      buff[u++] = str[i++];
      if (str[i] == ')' && bracket == 0)
        {
	  buff[u] = '\0';
	  return ;
        }
    }
}

char		**copy_tab(char **tab)
{
  int		i;
  char		**tab_cp;

  i = 0;
  while (tab[i] != NULL)
    i++;
  if ((tab_cp = xmalloc(sizeof(*tab) * (i + 1))) == NULL)
    {
      my_printf("%E", "Problem for gere bracket\n");
      return (NULL);
    }
  i = 0;
  while (tab[i] != NULL)
    {
      if ((tab_cp[i] = my_strdup(tab[i])) == NULL)
	{
	  free_tab(tab_cp);
	  my_printf("%E", "Problem for gere bracket\n");
	  return (NULL);
	}
      i++;
    }
  tab_cp[i] = NULL;
  return (tab_cp);
}

int		copy_info(t_info *info, t_info *info_cp)
{
  if ((info_cp->env = copy_tab(info->env)) == NULL)
    return (EXIT_FAILURE);
  if ((info_cp->set = copy_tab(info->set)) == NULL)
    return (EXIT_FAILURE);
  if ((info_cp->path = copy_tab(info->path)) == NULL)
    return (EXIT_FAILURE);
/*   info_cp->prompt = my_strdup(info->prompt); */
  info_cp->last_status = info->last_status;
  info_cp->history = info->history;
  info_cp->nbr_cmd = info->nbr_cmd;
  info_cp->pwd = my_strdup(info->pwd);
  info_cp->last_pwd = my_strdup(info->last_pwd);
  return (EXIT_SUCCESS);
}

void		free_info(t_info *info)
{
  free_tab(info->env);
  free_tab(info->set);
  free_tab(info->path);
/*   xfree(info->prompt); */
  xfree(info->pwd);
  xfree(info->last_pwd);
}

int		gere_bracket(t_info *info, char *str, int flag)
{
  char		buff[BUFF_COMPL];
  t_info	info_cp;
  int		value;
  char		*tab[3];

  gere_bracket_copy_between_bracket(str, buff);
  if (copy_info(info, &info_cp) == EXIT_FAILURE)
    return (status(info, EXIT_FAILURE));
  value = gere(&info_cp, buff, flag);
  free_info(&info_cp);
  tab[0] = "cd";
  if ((tab[1] = info->pwd) == NULL)
    return (status(info, EXIT_FAILURE));
  tab[2] = NULL;
  my_cd(info, tab);
  return (status(info, value));
}
