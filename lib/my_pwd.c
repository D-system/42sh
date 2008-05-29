/*
** my_pwd.c for  in /u/epitech_2012/brenne_t/cu/42sh/gp2/work
**
** Made by thomas brennetot
** Login   <brenne_t@epitech.net>
**
** Started on  Thu May  8 15:21:07 2008 thomas brennetot
** Last update Fri May 30 00:55:01 2008 thomas brennetot
*/

#include "42.h"
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>

#define	BS	512

uint		get_ino(char *rec)
{
  uint		ino;
  struct dirent *read;
  DIR		*rep;

  rep = opendir(rec);
  while ((read = readdir(rep)))
    {
      if ((read->d_name[0] == '.') && (read->d_name[1] == 0))
	{
	  ino = read->d_ino;
	  closedir(rep);
	  return (ino);
	}
    }
  closedir(rep);
  return (0);
}

char		*get_name(uint ino, char *rec)
{
  struct dirent *read;
  DIR		*rep;
  char		*name;

  rep = opendir(rec);
  while ((read = readdir(rep)))
    {
      if (read->d_ino == ino)
	{
	  name = my_strdup(read->d_name);
	  closedir(rep);
	  return (name);
	}
    }
  closedir(rep);
  return (NULL);
}

char		*get_pwd(char *pwd, char *rec)
{
  uint		ino;
  char		*name;

  if ((ino = get_ino(rec)) <= 2)
    {
      strcat(pwd, "/");
      strcat(pwd, "afs");
      return (NULL);
    }
  strcat(rec, "../");
  if ((name = get_name(ino, rec)) == NULL)
    return (NULL);
  get_pwd(pwd, rec);
  strcat(pwd, "/");
  strcat(pwd, name);
  xfree(name);
  return (pwd);
}

void		*t_pwd(void *ptr)
{
  char		*pwd;
  char		*rec;

  pwd = xmalloc(sizeof(char) * BS);
  my_memset(pwd, 0, sizeof(char) * BS);
  rec = xmalloc(sizeof(char) * BS);
  my_memset(rec, 0, sizeof(char) * BS);
  strcat(rec, "./");
  get_pwd(pwd, rec);
  ptr = pwd;
  xfree(rec);
  return (ptr);
}

char		*my_pwd()
{
  void		*ptr;

  ptr = NULL;
  ptr = t_pwd(ptr);
  return ((char*)ptr);
}
