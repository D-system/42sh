/*
** gere_bracket.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Mon Apr 21 17:55:55 2008 thomas brennetot
** Last update Thu May  8 16:42:15 2008 thomas brennetot
*/

#include <stdlib.h>
#include "42.h"

void	gere_bracket_copy_between_bracket(char *str, char *buff)
{
  int	i;
  int	u;
  int	start;
  int	bracket;

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

int		gere_bracket(t_info *info, char *str, int flag)
{
  char		buff[BUFF_COMPL];
  t_info	info_cp;
  int		value;
  char		*tab[3];

  gere_bracket_copy_between_bracket(str, buff);
  my_memcpy(&info_cp, info, sizeof(t_info));
  value = gere(&info_cp, buff, flag);
  tab[0] = "cd";
  if ((tab[1] = fetch_env(info->env, "PWD", "=") + 4) == NULL)
    return (status(info, EXIT_FAILURE));
  tab[2] = NULL;
  my_cd(info, tab);
  return (status(info, value));
}
