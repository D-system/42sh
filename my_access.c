/*
** my_access.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Wed Apr 23 18:00:20 2008 thomas brennetot
** Last update Wed May 21 10:48:18 2008 aymeric derazey
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include "42.h"
#define CONCAT_SIZE 512

void	my_strcat_mode(char *dest, char *src1, char *src2)
{
  int	idest;
  int	i;

  idest = 0;
  i = 0;
  while (src1[idest] != '\0')
    {
      dest[idest] = src1[idest];
      idest++;
    }
  dest[idest++] = '/';
  while (src2[i] != '\0')
    dest[idest++] = src2[i++];
  dest[idest] = '\0';
}

int	my_access_wd(char **tab)
{
  if (access(tab[0], F_OK) != -1)
    {
      if (access(tab[0], X_OK) != -1)
	return (EXIT_SUCCESS);
      else
	my_printf("%E%E", tab[0], ": Access Denied\n");
    }
  else
    my_printf("%E%E", tab[0], ": command not found\n");
  return (EXIT_FAILURE);
}

int	my_access(t_info *info, char **tab)
{
  int	ipath;
  char	concat_path_bin[CONCAT_SIZE];

  ipath = 0;
  if (my_strncmp(tab[0], "./", 2) == 0 || my_strncmp(tab[0], "/", 1) == 0)
    return (my_access_wd(tab));
  else
    while (info->path[ipath] != NULL)
      {
	my_strcat_mode(concat_path_bin, info->path[ipath], tab[0]);
	if (access(concat_path_bin, F_OK) != -1)
	  {
	    if (access(concat_path_bin, X_OK) != -1)
	      {
		xfree(tab[0]);
		tab[0] = my_strdup(concat_path_bin);
		return (EXIT_SUCCESS);
	      }
	    else
	      my_printf("%E%E", tab[0], ": Access Denied\n");
	  }
	ipath++;
      }
  my_printf("%E%E", tab[0], ": command not found\n");
  return (EXIT_FAILURE);
}
