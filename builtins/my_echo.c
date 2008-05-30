/*
** my_echo.c for 42sh in /u/epitech_2012/deraze_a/cu/rendu/c/42sh/gp2/work/builtins
**
** Made by aymeric derazey
** Login   <deraze_a@epitech.net>
**
** Started on  Fri May  2 23:57:18 2008 aymeric derazey
** Last update Fri May 30 22:28:26 2008 aymeric derazey
*/

#include "stdlib.h"
#include "42.h"

/*
** dans le cas d'un echo "$toto", va chercher et afficher le contenu de la variable.
*/

/* int	check_var(char *var, t_info *info) */
/* { */
/*   char	*line; */

/*   line = fetch_env(info->env, var + 1, "="); */
/*   if (line == NULL) */
/*     { */
/*       my_printf("%E%E", var + 1, ": Undefined variable\n"); */
/*       return (status(info, EXIT_FAILURE)); */
/*     } */
/*   else */
/*     my_putstr(line + my_strlen(var)); */
/*   return (EXIT_SUCCESS); */
/* } */

int	check_var(char *var, char **tab, char *delim)
{
  char	*line;

  if ((line = fetch_env(tab, var + 1, delim)) == NULL)
    return (EXIT_FAILURE);
  else
    {
      my_putstr(line + my_strlen(var));
      my_printf(" ");
    }
  return (EXIT_SUCCESS);
}

/*
** Builtin echo, gestion de l'affichage de variable d'ENV et de set.
*/

int	my_echo(t_info *info, char **tab)
{
  int	i;

  i = 1;
  while (tab[i] != NULL)
    {
      if (tab[i] == NULL)
	my_printf("\n");
      else if (tab[i][0] == '$')
	{
	  if (check_var(tab[i], info->env, "=") == EXIT_FAILURE)
	    if (check_var(tab[i], info->set, "\t") == EXIT_FAILURE)
	      {
		my_printf("%E%E", tab[i] + 1, ": Undefined variable\n");
		return (status(info, EXIT_FAILURE));
	      }
	}
      else
	my_printf("%s ", tab[i]);
      i++;
    }
  my_printf("\n");
  return (EXIT_SUCCESS);
}
