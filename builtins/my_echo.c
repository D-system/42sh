/*
** my_echo.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
** 
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
** 
** Started on  Fri May  2 23:57:18 2008 aymeric derazey
** Last update Sat May  3 12:12:11 2008 aymeric derazey
*/

#include "stdlib.h"
#include "../42.h"

int	check_var(char *local_var, t_info *info)
{
  char	*line;

  line = fetch_env(info->env, local_var + 1);
  if (line == NULL)
    {
      my_printf("%E%E", local_var + 1, ": Undefined variable\n");
      return (status(info, EXIT_FAILURE));
    }
  else 
    {
      my_putstr(line + my_strlen(local_var));
      my_putchar('\n');
    }
  return (EXIT_SUCCESS);
}

/* nt	check_var(char *local_var, t_info *info) */
/* { */
/*   int	i; */
/*   int	j; */
/*   int	len; */
/*   char	*cpy; */

/*   len = my_strlen(local_var); */
/*   i = 0; */
/*   j = 0; */
/*   while (info->env[i] != NULL) */
/*     { */
/*       if (my_strncmp(local_var + 1, info->env[i], len - 1) == 0) */
/* 	{ */
/* 	  while (info->env[i][j] != '=') */
/* 	    j++; */
/* 	  my_putstr(info->env[i] + ++j); */
/* 	  return (EXIT_SUCCESS); */
/* 	} */
/*       i++; */
/*     } */
/*   if (info->env[i] == NULL) */
/*     { */
/*       my_printf("%s: Undefined variable\n", local_var + 1); */
/*       return (EXIT_FAILURE); */
/*     } */
/*   return (EXIT_SUCCESS); */
/* } */

int	my_echo(t_info *info, char **tab)
{
  if (tab[1] == NULL)
    my_printf("\n");
  else if (tab[1][0] == '$')
    {
      if (check_var(tab[1], info) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    my_printf("%s\n", tab[1]);
  return (EXIT_SUCCESS);
}
