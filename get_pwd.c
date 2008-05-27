/*
** get_pwd.c for  in /u/epitech_2012/lefebv_l/cu/public/42sh/get_pwd
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Tue May 27 16:22:35 2008 laurent lefebvre
** Last update Tue May 27 18:36:42 2008 laurent lefebvre
*/

#include "42.h"
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>

#define	BS	2048

/* IMPLEMENTATION IN PROGRESS */

/*
** Ajouter xopendir / xreaddir / xclosedir a err/
*/

int		get_ino()
{
  uint		ino;
  struct dirent *read;
  DIR		*rep;

  if (!(rep = opendir(".")))
    return (0);
  while ((read = readdir(rep)) != NULL)
    {
      if ((read->d_name[0] == '.') && (read->d_name[1] == 0))
	{
	  ino = read->d_ino;
	  if (closedir(rep) == -1)
	    return (0);
	  return (ino);
	}
    }
  closedir(rep);
  return (2);
}

char	*get_name(uint ino)
{
  struct dirent *read;
  DIR		*rep;
  char		*name;

  if (!(rep = opendir(".")))
    return (0);
  while ((read = readdir(rep)))
    {
      if (read->d_ino == ino)
	{
	  name = my_strdup(read->d_name);
	  if (closedir(rep) == -1)
	    return (NULL);
	  return (name);
	}
    }
  closedir(rep);  
  return (NULL);  
}

/*
** J'utilise strcat car my_strcat est mal code, il ne doit pas malloquer un nouveau pointeur,
** mais ecrire directement dans le premier argument. (man strcat)
*/

void		get_pwd(char *pwd)
{
  uint	ino;
  char	*name = "afs";
  
  if ((ino = get_ino()) <= 2)
    {
      strcat(pwd, "/");
      strcat(pwd, name);
      return ;
    }
  if (xchdir("../") == -1)
    return ;
  if ((name = get_name(ino)) == NULL)
    return ;
  get_pwd(pwd);
  strcat(pwd, "/");
  strcat(pwd, name);
  xfree(name);
}

char	*my_pwd(void)
{
  char	*pwd;

  pwd = xmalloc(sizeof(*pwd) * BS);
  my_memset(pwd, 0, sizeof(*pwd));
  get_pwd(pwd);
  xchdir(pwd);
  return (pwd);
}
