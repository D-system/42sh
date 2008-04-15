/*
** prompt.c for 42sh in /u/epitech_2012/lefebv_l/cu/public/42sh/official
** 
** Made by laurent lefebvre
** Login   <lefebv_l@epitech.net>
** 
** Started on  Fri Apr  4 17:28:39 2008 laurent lefebvre
** Last update Fri Apr 11 16:27:58 2008 thomas brennetot
*/

#include <stdlib.h>
#include "../42.h"
#define BUFF_PROMPT 1024

/*
** Affiche le prompt, gestion de l'isatty
*/

typedef struct	s_prompt
{
  char		c;
  void		(*func)();
  int		flag;
}		t_prompt;

t_prompt gl_prompt[] =
  {
    {'/', 0, 0},	/* pwd */
    {'~', 0, 0},	/* affiche '~' */
    {'c', 0, 0},	/* pwd depuis l'home */
    {'C', 0, 0},	/* pwd depuis l'home sans le '~/'*/
    {'h', 0, 0},	/* The current history event number */
    {'M', 0, 0},	/* The full hostname */
    {'m', 0, 0},	/* The hostname up to the first `.' */
    {'S', 0, 0},	/* Debut de la video inverse */
    {'s', 0, 0},	/* Fin de la video inverse */
    {'B', 0, 0},	/* Debut du mode 'gras' */
    {'b', 0, 0},	/* Fin du mode 'gras' */
    {'U', 0, 0},	/* Debut du mode 'surligne' */
    {'u', 0, 0},	/* Fin du mode 'surligne' */
    {'t', 0, 0},	/* The time of day in 12-hour AM/PM format */
    {'T', 0, 0},	/* Like `%t', but in 24-hour format */
    {'p', 0, 0},	/* Comme %t avec les secondes */
    {'P', 0, 0},	/* Comme %T avec les secondes */
    {'%', 0, 0},	/* '%' */
    {'n', 0, 0},	/* The user name */
    {'d', 0, 0},	/* The weekday in `Day' format. */
    {'D', 0, 0},	/* The day in `dd' format. */
    {'w', 0, 0},	/* The month in `Mon' format. */
    {'W', 0, 0},	/* The month in `mm' format. */
    {'y', 0, 0},	/* The year in `yy' format. */
    {'Y', 0, 0},	/* The year in `yyyy' format. */
    {'?', 0, 0},	/* Valeur de return de la derniere commande */
    {0, 0, 0},
  };


int	prompt(t_info *info)
{
  if (info->prompt == NULL)
    my_putchar('>');
  else
    {
      my_putstr(info->prompt);
    }
  return (EXIT_SUCCESS);
}
